# -*- coding: Utf-8 -*

from re import compile as regex_compile, Pattern
from typing import Any, Dict, Optional, Type

from .base import Response


class SpontaneousResponse(Response):

    __response_list: Dict[Type["SpontaneousResponse"], Pattern[str]] = dict()

    def __init_subclass__(cls, /, *, response: str) -> None:
        super().__init_subclass__()
        cls.__response_list[cls] = regex_compile(response)

    def __new__(cls, *args: Any, **kwargs: Any) -> Any:
        if cls is SpontaneousResponse:
            raise TypeError(f"{cls.__name__} can't be instantiated")
        return super().__new__(cls)

    @classmethod
    def match(cls, response: str) -> Optional["SpontaneousResponse"]:
        for ResponseClass, response_pattern in cls.__response_list.items():
            if response_pattern.match(response):
                return ResponseClass(response)
        return None


class DeadResponse(SpontaneousResponse, response=r"dead"):
    pass
