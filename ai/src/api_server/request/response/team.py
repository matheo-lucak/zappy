# -*- coding: Utf-8 -*

from typing import Optional
from .base import Response
from .exceptions import ResponseParsingError

class TeamResponse(Response):

    def __init__(self, response: str) -> None:
        super().__init__(response)
        self.__client_num: Optional[int] = None

        if response == "ko":
            return
        if response.isdigit():
            self.__client_num = int(response)
        else:
            raise ResponseParsingError(f"Should receive 'ko' or a positive integer. Received {repr(response)}.")

    @property
    def client_num(self) -> Optional[int]:
        return self.__client_num