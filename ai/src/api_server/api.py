# -*- coding: Utf-8 -*

from sys import stderr
from socket import socket, AF_INET, SOCK_STREAM
from select import select
from typing import Callable, Iterator, List, Optional, Type, TypeVar, cast

from .request import BaseRequest, Request
from .request.response import Response, SpontaneousResponse
from .request.response.exceptions import ResponseError
from ..log import Logger

R = TypeVar("R", bound=Response)


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
        self.__buffer: str = str()

    def __del__(self) -> None:
        self.__socket.close()
        print(f"Disconnected from {self.__machine}:{self.__port}")

    def send(self, request: BaseRequest[R]) -> None:
        self.__requests.append(cast(Request, request))

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

        if self.__pending_responses:
            return create_response()
        if wait:
            self.__fetch_all_responses()
        return create_response() if self.__pending_responses else None

    def has_request_to_handle(self, request_type: Type[BaseRequest[R]]) -> bool:
        if any(type(request) is request_type for request in self.__pending_requests):
            return True
        if any(type(request) is request_type for request in self.__requests):
            return True
        return False

    def flush_spontaneous_responses(self) -> List[SpontaneousResponse]:
        responses: List[SpontaneousResponse] = self.__spontaneous_responses
        self.__spontaneous_responses = list()
        return responses

    def fetch(self) -> None:
        pending_responses: List[str] = self.__pending_responses
        self.__pending_responses = list()
        for response in pending_responses:
            self.__parse_response(response)

        has_requests: Callable[[], bool] = lambda: bool(self.__requests) and (
            len(self.__pending_requests) < self.MAX_PENDING_REQUEST
        )

        timeout: float = 0.05

        while has_requests() and self.__socket in select([], [self.__socket], [], timeout)[1]:
            request: Request = self.__requests.pop(0)
            self.__send_request_to_server(str(request))
            self.__pending_requests.append(request)

        if self.__socket in select([self.__socket], [], [], timeout)[0]:
            self.__fetch_all_responses()

    def __send_request_to_server(self, request: str) -> None:
        Logger.print(2, f"--> {repr(request)}")
        data: bytes = (request + BaseRequest.END_REQUEST).encode()
        self.__socket.sendall(data)

    def __recv_response_from_server(self) -> Iterator[str]:
        def read_socket(chunck_size: int) -> Iterator[bytes]:
            while True:
                try:
                    data: bytes = self.__socket.recv(chunck_size)
                except BlockingIOError:
                    break
                if self.__socket.getblocking() is False:
                    self.__socket.setblocking(True)
                length: int = len(data)
                if length == 0:
                    raise EOFError
                yield data
                if length < chunck_size:
                    break
                self.__socket.setblocking(False)

        for data in read_socket(4096):
            self.__buffer += data.decode(errors="ignore")
            while True:
                idx: int = self.__buffer.find(Response.END_RESPONSE)
                if idx < 0:
                    break
                response: str = self.__buffer[:idx].strip()
                self.__buffer = self.__buffer[idx + 1 :]
                Logger.print(2, f"<-- {repr(response)}")
                yield response

    def __fetch_all_responses(self) -> None:
        for response in self.__recv_response_from_server():
            self.__parse_response(response)

    def __parse_response(self, received_response: str) -> None:
        response: Optional[SpontaneousResponse] = SpontaneousResponse.find(received_response)
        if response is not None:
            self.__spontaneous_responses.append(response)
        elif not self.__pending_requests:
            self.__pending_responses.append(received_response)
        else:
            request: Request = self.__pending_requests.pop(0)
            try:
                request.set_response(received_response)
            except ResponseError as e:
                print(f"{type(e).__name__}: {e}", file=stderr)
                print(f"-> The request {repr(request)} will be sent again to the server.", file=stderr)
                self.send(request)
