# -*- coding: Utf-8 -*

from re import compile as regex_compile, Pattern, Match
from typing import Any, List, Optional, Type, cast

from .base import Response
from .exceptions import ResponseError, ResponseParsingError


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
            raise ResponseParsingError(response, "Doesn't match pattern")
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
            except ResponseError:
                continue
        return None

    @classmethod
    def get_pattern(cls) -> Pattern[str]:
        if cls is SpontaneousResponse:
            raise TypeError(f"The base class {cls.__name__} does not have a regex pattern")
        return cast(Pattern[str], getattr(cls, "__pattern__"))


class DeadResponse(SpontaneousResponse, response=r"dead"):
    pass


class MessageResponse(SpontaneousResponse, response=r"message +([0-9]+) *, *([^\s].+)"):
    def __init__(self, response: str) -> None:
        super().__init__(response)

        self.__tile: int = int(self.match.group(1))
        self.__text: str = self.match.group(2)

    @property
    def tile(self) -> int:
        return self.__tile

    @property
    def text(self) -> str:
        return self.__text
