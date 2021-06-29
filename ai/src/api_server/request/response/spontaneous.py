# -*- coding: Utf-8 -*

from re import compile as regex_compile, Pattern, Match
from typing import Any, List, Optional, Type, cast

from .base import Response
from .exceptions import SpontaneousResponseMatchError, ResponseParsingError


class SpontaneousResponse(Response):

    __response_list: List[Type["SpontaneousResponse"]] = list()

    def __init_subclass__(cls, /, *, response: str) -> None:
        super().__init_subclass__()
        cls.__response_list.append(cls)
        setattr(cls, "__pattern__", regex_compile(response))

    def __new__(cls, *args: Any, **kwargs: Any) -> Any:
        if cls is SpontaneousResponse:
            raise TypeError(f"{cls.__name__} can't be instantiated")
        return super().__new__(cls)

    def __init__(self, response: str) -> None:
        match: Optional[Match[str]] = self.get_pattern().match(response)
        if match is None:
            raise SpontaneousResponseMatchError(response, "Doesn't match pattern")
        super().__init__(response)
        self.__match: Match[str] = match

    @property
    def match(self) -> Match[str]:
        return self.__match

    @staticmethod
    def find(response: str) -> Optional["SpontaneousResponse"]:
        for ResponseClass in SpontaneousResponse.__response_list:
            try:
                return ResponseClass(response)
            except SpontaneousResponseMatchError:
                continue
        return None

    @classmethod
    def get_pattern(cls) -> Pattern[str]:
        if cls is SpontaneousResponse:
            raise AttributeError(f"The base class {cls.__name__} does not have a regex pattern")
        return cast(Pattern[str], getattr(cls, "__pattern__"))


class DeadResponse(SpontaneousResponse, response=r"dead"):
    pass


class MessageResponse(SpontaneousResponse, response=r"message +([^\s]+) *, *([^\s].+)"):
    def __init__(self, response: str) -> None:
        super().__init__(response)

        tile: str = self.match.group(1)
        if not tile.isdigit():
            raise ResponseParsingError(response, "Tile must be a positive integer")
        self.__tile: int = int(tile)

        if self.__tile not in range(9):
            raise ResponseParsingError(response, "Tile must be between 0 and 8")

        self.__text: str = self.match.group(2)

    @property
    def tile(self) -> int:
        return self.__tile

    @property
    def text(self) -> str:
        return self.__text


class EjectedResponse(SpontaneousResponse, response=r"eject: +([^\s]+)"):
    def __init__(self, response: str) -> None:
        super().__init__(response)

        tile: str = self.match.group(1)
        if not tile.isdigit():
            raise ResponseParsingError(response, "Tile must be a positive integer")
        self.__tile: int = int(tile)

        valid_tiles: List[int] = [1, 3, 5, 7]
        if self.__tile not in valid_tiles:
            raise ResponseParsingError(response, f"Tile must be in {valid_tiles}")

    @property
    def tile(self) -> int:
        return self.__tile
