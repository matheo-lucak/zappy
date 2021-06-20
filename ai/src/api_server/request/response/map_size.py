# -*- coding: Utf-8 -*

from typing import List
from .base import Response
from .exceptions import ResponseParsingError

class MapSizeAtBeginningResponse(Response):

    def __init__(self, response: str) -> None:
        super().__init__(response)
        self.__w: int = 0
        self.__h: int = 0

        splitted: List[str] = response.split()
        if len(splitted) != 2 or any(not val.isdigit() for val in splitted):
            raise ResponseParsingError(response, "Invalid map size response")
        self.__w = int(splitted[0])
        self.__h = int(splitted[1])

    @property
    def width(self) -> int:
        return self.__w

    @property
    def height(self) -> int:
        return self.__h
