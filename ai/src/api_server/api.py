# -*- coding: Utf-8 -*

from socket import socket, AF_INET, SOCK_STREAM
from select import select

from src.api_server.request import BaseRequest
from .request import Request
from .request.response import Response, SpontaneousResponse
from typing import Iterator, List, Optional, Type, TypeVar, cast


R = TypeVar("R", bound=Response)

class MySocket(socket):

    def recvall(self, chunck_size: int) -> bytes:

        def read_socket() -> Iterator[bytes]:
            while True:
                data: bytes = self.recv(chunck_size)
                if len(data) == 0:
                    break
                yield data
                if len(data) < chunck_size:
                    break

        buffer: bytes = bytes()

        for data in read_socket():
            buffer += data

        return buffer

class APIServer:

    def __init__(self, machine: str, port: int) -> None:
        timeout: int = 10 #seconds
        self.__socket: MySocket = MySocket(AF_INET, SOCK_STREAM)
        print(f"Connecting to {machine} at port {port}... (Timeout: {timeout})")
        self.__socket.settimeout(timeout)
        self.__socket.connect((machine, port))
        self.__socket.settimeout(None)
        print("Connected")
        self.__requests: List[Request] = list()
        self.__pending_requests: List[Request] = list()
        self.__responses: List[SpontaneousResponse] = list()
        self.__pending_responses: List[str] = list()
        self.__buffer: str = str()

    def __del__(self) -> None:
        self.__socket.close()
        print("Disconnected")

    def send(self, request: BaseRequest[R]) -> None:
        self.__requests.append(cast(Request, request))

    def send_and_wait_for_response(self, request: BaseRequest[R]) -> R:
        self.send(request)
        while request.response is None:
            self.fetch()
        return request.response

    def recv(self, response_class: Type[R], *, wait: bool = True) -> Optional[R]:
        if self.__pending_responses:
            return response_class(self.__pending_responses.pop(0))
        if wait:
            self.__fetch_all_responses()
        return response_class(self.__pending_responses.pop(0)) if self.__pending_responses else None

    def flush_spontaneous_responses(self) -> List[SpontaneousResponse]:
        responses: List[SpontaneousResponse] = self.__responses
        self.__responses = list()
        return responses

    def fetch(self) -> None:
        pending_responses: List[str] = self.__pending_responses
        self.__pending_responses = list()
        for response in pending_responses:
            self.__parse_response(response)

        rlist, wlist, _ = select([self.__socket], [self.__socket] if self.__requests else [], [], 0.05)

        if self.__socket in rlist:
            self.__fetch_all_responses()

        if self.__socket in wlist:
            request: Request = self.__requests.pop(0)
            self.__send_request_to_server(str(request))
            self.__pending_requests.append(request)

    def __send_request_to_server(self, request: str) -> None:
        print(f"--> {repr(request)}")
        data: bytes = (request + BaseRequest.END_REQUEST).encode("utf-8")
        self.__socket.sendall(data)

    def __recv_response_from_server(self) -> Iterator[str]:
        self.__buffer += self.__socket.recvall(4096).decode("utf-8")
        while True:
            idx: int = self.__buffer.find(Response.END_RESPONSE)
            if idx < 0:
                break
            response: str = self.__buffer[:idx]
            self.__buffer = self.__buffer[idx + 1:]
            print(f"<-- {repr(response)}")
            yield response

    def __fetch_all_responses(self) -> None:
        for response in self.__recv_response_from_server():
            self.__parse_response(response)

    def __parse_response(self, received_response: str) -> None:
        for spontaneous_response in SpontaneousResponse.list():
            if received_response.startswith(spontaneous_response):
                self.__responses.append(SpontaneousResponse.create(spontaneous_response, received_response))
                return
        if not self.__pending_requests:
            self.__pending_responses.append(received_response)
            return
        request: Request = self.__pending_requests.pop(0)
        request.set_response(received_response)
