# -*- coding: Utf-8 -*

from socket import socket, AF_INET, SOCK_STREAM
from .request import ZappyRequest, ZappyResponse
from typing import List, Optional

class APIServer:

    def __init__(self, machine: str, port: int) -> None:
        self.__socket: socket = socket(AF_INET, SOCK_STREAM)
        # self.__socket.settimeout(10)
        # self.__socket.connect((machine, port))
        # self.__socket.settimeout(None)
        self.__requests: List[ZappyRequest] = list()
        self.__replies: List[ZappyResponse] = list()

    def __del__(self) -> None:
        self.__socket.close()

    def send(self, request: ZappyRequest) -> None:
        self.__requests.append(request)

    def receive(self) -> Optional[ZappyResponse]:
        if len(self.__replies) == 0:
            return None
        return self.__replies.pop(0)