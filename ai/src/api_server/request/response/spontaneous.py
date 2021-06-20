# -*- coding: Utf-8 -*

from re import compile as regex_compile, Pattern, Match
from typing import Any, Dict, Optional, Type

from .base import Response
from .exceptions import ResponseParsingError


class SpontaneousResponse(Response):

    __response_list: Dict[Type["SpontaneousResponse"], Pattern[str]] = dict()

    def __init_subclass__(cls, /, *, response: str) -> None:
        super().__init_subclass__()
        cls.__response_list[cls] = regex_compile(response)

    def __new__(cls, *args: Any, **kwargs: Any) -> Any:
        if cls is SpontaneousResponse:
            raise TypeError(f"{cls.__name__} can't be instantiated")
        return super().__new__(cls)

    def __init__(self, response: Match[str]) -> None:
        super().__init__(response.string)

    @staticmethod
    def match(response: str) -> Optional["SpontaneousResponse"]:
        for ResponseClass, response_pattern in SpontaneousResponse.__response_list.items():
            match: Optional[Match[str]] = response_pattern.match(response)
            if match:
                return ResponseClass(match)
        return None

    @classmethod
    def get_pattern(cls) -> Pattern[str]:
        if cls is SpontaneousResponse:
            raise TypeError(f"The base class {cls.__name__} does not have a regex pattern")
        return cls.__response_list[cls]


class DeadResponse(SpontaneousResponse, response=r"dead"):
    pass


class MessageResponse(SpontaneousResponse, response=r"message +([0-9]+) *, *(.+)"):
    def __init__(self, response: Match[str]) -> None:
        super().__init__(response)

        try:
            self.__tile: int = int(response.group(1))
            self.__text: str = response.group(2)
        except (ValueError, IndexError) as e:
            raise ResponseParsingError from e

    @property
    def tile(self) -> int:
        return self.__tile

    @property
    def text(self) -> str:
        return self.__text
