 # -*- coding: Utf-8 -*

from .response import ZappyResponse
SEPARATOR: str = " "

class ZappyRequest:

    def __init__(self, command: str, *args: str) -> None:
        self.__command: str = command
        self.__args: str = SEPARATOR.join(args)

    def __str__(self) -> str:
        return f"{self.__command}{SEPARATOR}{self.__args}\n"

    def make_response(self, response: str) -> ZappyResponse:
        raise NotImplementedError