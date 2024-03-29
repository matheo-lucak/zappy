# -*- coding: Utf-8 -*

from socket import socket, AF_INET, SOCK_STREAM
from select import select
from typing import Callable, Dict, Iterator, List, Optional, Tuple, Type, TypeVar, cast

from .request import BaseRequest, RequestPlaceholder, Request
from .request.response import Response, SpontaneousResponse, MultiResponse
from .request.response.exceptions import ResponseError
from ..log import Logger

R = TypeVar("R", bound=Response)


class MultiResponseNotHandledError(ResponseError):
    def __init__(self, response_class: Type[MultiResponse]) -> None:
        message: str = "Subclass of MultiResponse: Not handled"
        super().__init__(response_class.__name__, message)


SpontaneousResponseHandler = Callable[[List[SpontaneousResponse]], None]
FetchCallback = Callable[[], None]

RequestPlaceholderVar = TypeVar("RequestPlaceholderVar")


class APIServer:

    MAX_PENDING_REQUEST: int = 10

    def __init__(self, machine: str, port: int) -> None:
        timeout: int = 10  # seconds
        self.__machine: str = machine
        self.__port: int = port

        self.__socket: socket = socket(AF_INET, SOCK_STREAM)
        print(f"Connecting to {machine} at port {port}... (Timeout: {timeout}s)")
        self.__socket.settimeout(timeout)
        self.__socket.connect((machine, port))
        self.__socket.settimeout(None)
        print("Connected")

        self.__requests: List[Request] = list()
        self.__pending_requests: List[Request] = list()
        self.__spontaneous_responses: List[SpontaneousResponse] = list()
        self.__pending_responses: List[str] = list()
        self.__multiresponse_buffer: Dict[Request, List[str]] = dict()
        self.__buffer: str = str()

        self.__fetch_callbacks: List[FetchCallback] = list()

        self.__spontaneous_response_handler: Optional[SpontaneousResponseHandler] = None

    def __del__(self) -> None:
        self.close()

    def close(self) -> None:
        self.__socket.close()
        print(f"Disconnected from {self.__machine}:{self.__port}")

    def send(self, request: BaseRequest[R], *, have_priority: bool = False) -> None:
        if not have_priority:
            self.__requests.append(cast(Request, request))
        else:
            self.__requests.insert(0, cast(Request, request))
        self.__send_all_requests()

    def recv(self, response_class: Type[R], *, wait: bool = True, handle_response_error: bool = False) -> Optional[R]:
        def create_response() -> Optional[R]:
            try:
                rp: R = response_class(self.__pending_responses[0])
            except ResponseError as e:
                if not handle_response_error:
                    raise e from None
                return None
            self.__pending_responses.pop(0)
            return rp

        if issubclass(response_class, MultiResponse):
            raise MultiResponseNotHandledError(response_class)

        if self.__pending_responses:
            return create_response()
        if wait:
            self.__fetch_all_responses()
            self.__handle_pending_requests()
        return create_response() if self.__pending_responses else None

    def has_request_to_handle(self, request_type: Optional[Type[BaseRequest[R]]] = None) -> bool:
        if request_type is None:
            return len(self.__pending_requests) > 0 or len(self.__requests) > 0
        if any(type(request) is request_type for request in self.__pending_requests):
            return True
        if any(type(request) is request_type for request in self.__requests):
            return True
        return False

    def remove_request_placeholder(self, request_type: Type[RequestPlaceholderVar]) -> Optional[RequestPlaceholderVar]:
        if not issubclass(request_type, RequestPlaceholder):
            return None
        for request_list in [self.__pending_requests, self.__requests]:
            for i, request in enumerate(request_list):
                if isinstance(request, RequestPlaceholder) and type(request) == request_type:
                    return cast(RequestPlaceholderVar, self.__pending_requests.pop(i))
        return None

    def flush_spontaneous_responses(self) -> List[SpontaneousResponse]:
        responses: List[SpontaneousResponse] = self.__spontaneous_responses
        self.__spontaneous_responses = list()
        return responses

    def set_spontaneous_response_handler(self, callback: Optional[SpontaneousResponseHandler]) -> None:
        self.__spontaneous_response_handler = callback

    def add_fetch_callback(self, callback: FetchCallback) -> None:
        if callback not in self.__fetch_callbacks:
            self.__fetch_callbacks.append(callback)

    def remove_fetch_callback(self, callback: FetchCallback) -> None:
        try:
            self.__fetch_callbacks.remove(callback)
        except ValueError:
            pass

    def fetch(self, use_fetch_callbacks: bool = True) -> None:
        if use_fetch_callbacks:
            for callback in self.__fetch_callbacks:
                callback()

        self.__send_all_requests()

        if self.__socket in select([self.__socket], [], [], 0.001)[0]:
            self.__fetch_all_responses()

        self.__handle_pending_requests()

        if callable(self.__spontaneous_response_handler):
            self.__spontaneous_response_handler(self.flush_spontaneous_responses())

    def __send_all_requests(self) -> None:
        def has_requests() -> bool:
            return bool(self.__requests) and (len(self.__pending_requests) < self.MAX_PENDING_REQUEST)

        def send_request_to_server(request: str) -> None:
            Logger.print(1, f"--> {repr(request)}")
            data: bytes = (request + BaseRequest.END_REQUEST).encode()
            self.__socket.sendall(data)

        while has_requests() and self.__socket in select([], [self.__socket], [], 0)[1]:
            request: Request = self.__requests.pop(0)
            if not isinstance(request, RequestPlaceholder):
                send_request_to_server(str(request))
            self.__pending_requests.append(request)

    def __fetch_all_responses(self) -> None:
        def read_socket(chunck_size: int) -> Iterator[bytes]:
            while True:
                try:
                    data: bytes = self.__socket.recv(chunck_size)
                except BlockingIOError:
                    break
                length: int = len(data)
                if length == 0:
                    raise EOFError
                yield data
                if length < chunck_size:
                    break
                if self.__socket not in select([self.__socket], [], [], 0)[0]:
                    break

        def recv_response_from_server() -> Iterator[str]:
            for data in read_socket(4096):
                self.__buffer += data.decode(errors="ignore")
                while True:
                    idx: int = self.__buffer.find(Response.END_RESPONSE)
                    if idx < 0:
                        break
                    response: str = self.__buffer[:idx].strip()
                    self.__buffer = self.__buffer[idx + len(Response.END_RESPONSE) :]
                    Logger.print(1, f"<-- {repr(response)}")
                    yield response

        for received_response in recv_response_from_server():
            try:
                response: Optional[SpontaneousResponse] = SpontaneousResponse.find(received_response)
            except ResponseError as e:
                print(f"Spontaneous response error: {type(e).__name__}: {e}")
                continue
            if response is not None:
                self.__spontaneous_responses.append(response)
            else:
                self.__pending_responses.append(received_response)

    def __handle_pending_requests(self) -> None:
        nb_missing_responses: int
        missing_responses: List[str]

        while self.__pending_requests:
            if not self.__pending_responses:
                break
            request: Request = self.__pending_requests[0]
            try:
                response_class: Type[Response] = request.get_response_type()
                if issubclass(response_class, MultiResponse):
                    if response_class.wait_for_all():
                        if request not in self.__multiresponse_buffer:
                            self.__multiresponse_buffer[request] = list()
                        response_buffer: List[str] = self.__multiresponse_buffer[request]
                        nb_missing_responses = response_class.nb_responses() - len(response_buffer)
                        response_buffer.extend(self.__pending_responses[:nb_missing_responses])
                        self.__pending_responses = self.__pending_responses[nb_missing_responses:]
                        if len(response_buffer) == response_class.nb_responses():
                            request.response = response_class(*response_buffer)
                            self.__multiresponse_buffer.pop(request)
                            self.__remove_first_request()
                    else:
                        former_responses: Tuple[str, ...] = tuple()
                        if isinstance(request.response, MultiResponse):
                            former_responses = request.response.list
                        nb_missing_responses = response_class.nb_responses() - len(former_responses)
                        missing_responses = self.__pending_responses[:nb_missing_responses]
                        self.__pending_responses = self.__pending_responses[nb_missing_responses:]
                        request.response = response_class(*former_responses, *missing_responses)
                        if request.response.complete:
                            self.__remove_first_request()
                else:
                    request.response = response_class(self.__pending_responses.pop(0))
                    self.__remove_first_request()
            except ResponseError as e:
                print(f"{type(e).__name__} for {repr(str(request))}: {e}")
                self.__remove_first_request()

    def __remove_first_request(self) -> None:
        request: Request = self.__pending_requests.pop(0)
        nb_ticks: int = request.get_process_time()
        for rq in self.__pending_requests:
            rq.add_ticks(nb_ticks)
