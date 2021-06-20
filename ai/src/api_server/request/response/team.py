# -*- coding: Utf-8 -*

from typing import Optional
from .base import Response
from .exceptions import ResponseParsingError

class TeamResponse(Response):

    def __init__(self, response: str) -> None:
        super().__init__(response)
        self.__client_num: Optional[int] = None

    def parse(self, response: str) -> None:
        if response == "ko":
            self.__client_num = None
        elif not response.isdigit():
            raise ResponseParsingError(f"Should received 'ko' or a positive integer. Recevied {repr(response)}.")
        else:
            self.__client_num = int(response)

    @property
    def client_num(self) -> Optional[int]:
        return self.__client_num