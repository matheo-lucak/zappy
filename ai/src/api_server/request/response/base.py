# -*- coding: Utf-8 -*

from re import compile as regex_compile, Pattern
from typing import Any, Dict, ItemsView, Type

Regex = Pattern[str]

class MetaResponse(type):

    def __call__(self, *args: Any, **kwds: Any) -> "Response":
        obj: "Response" = super().__call__(*args, **kwds)
        obj.parse(str(obj))
        return obj

class Response(metaclass=MetaResponse):
    
    END_RESPONSE: str = "\n"

    def __init__(self, response: str) -> None:
        self.__response: str = response

    def __repr__(self) -> str:
        return f"<{type(self).__name__}({repr(self.__response)})>"

    def __str__(self) -> str:
        return self.__response

    def parse(self, response: str) -> None:
        pass

class SpontaneousResponse(Response):
    
    __response_list: Dict[Type["SpontaneousResponse"], Regex] = dict()

    def __init_subclass__(cls, /, *, response: Regex) -> None:
        cls.__response_list[cls] = regex_compile(response)
        return super().__init_subclass__()

    @classmethod
    def list(cls) -> ItemsView[Type["SpontaneousResponse"], Regex]:
        return cls.__response_list.items()