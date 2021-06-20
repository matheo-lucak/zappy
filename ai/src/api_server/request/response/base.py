# -*- coding: Utf-8 -*

from re import compile as regex_compile, Pattern
from typing import Any, Dict, Optional, NewType, Type

Regex = NewType("Regex", str)

class Response:
    
    END_RESPONSE: str = "\n"

    def __init__(self, response: str) -> None:
        self.__response: str = response

    def __repr__(self) -> str:
        return f"<{type(self).__name__}({repr(self.__response)})>"

    def __str__(self) -> str:
        return self.__response

class SpontaneousResponse(Response):
    
    __response_list: Dict[Type["SpontaneousResponse"], Pattern[str]] = dict()

    def __init_subclass__(cls, /, *, response: Regex) -> None:
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