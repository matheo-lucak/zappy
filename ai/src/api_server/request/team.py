# -*- coding: Utf-8 -*

from typing import Optional

from .base import BaseRequest
from .response import Response
from .response.exceptions import ResponseParsingError


class TeamResponse(Response):
    def __init__(self, response: str) -> None:
        super().__init__(response)
        self.__client_num: Optional[int] = None

        if response == "ko":
            return
        if not response.isdigit():
            raise ResponseParsingError(response, "Should receive 'ko' or a positive integer")
        self.__client_num = int(response)

    @property
    def client_num(self) -> Optional[int]:
        return self.__client_num


class TeamRequest(BaseRequest[TeamResponse]):
    def __init__(self, team_name: str) -> None:
        super().__init__(team_name)
