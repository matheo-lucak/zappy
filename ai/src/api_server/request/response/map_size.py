# -*- coding: Utf-8 -*

from typing import List
from .response import Response
from .exceptions import ResponseParsingError

class MapSizeAtBeginningResponse(Response):

    def __init__(self, response: str) -> None:
        super().__init__(response)
        self.__w: int = 0
        self.__h: int = 0

    @property
    def width(self) -> int:
        return self.__w

    @property
    def height(self) -> int:
        return self.__h

    def parse(self, response: str) -> None:
        splitted: List[str] = response.split(" ")
        if len(splitted) != 2 or any(not val.isdigit() for val in splitted):
            raise ResponseParsingError(f"Invalid map size response: '{repr(response)}'")
        self.__w = int(splitted[0])
        self.__h = int(splitted[1])

class MapSizeInGameResponse(Response):
    
    def parse(self, response: str) -> None:
        pass