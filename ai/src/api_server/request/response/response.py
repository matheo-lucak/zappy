# -*- coding: Utf-8 -*

from typing import Any, Dict, List, Type
from .exceptions import ResponseInitError

class MetaResponse(type):

    def __call__(self, *args: Any, **kwds: Any) -> Any:
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
    
    __response_list: Dict[str, Type["SpontaneousResponse"]] = dict()

    def __init_subclass__(cls, /, *, response: str) -> None:
        if response in cls.__response_list:
            raise ResponseInitError(f"A spontaneous exception {repr(response)} already exists: {repr(cls.__response_list[response])}")
        cls.__response_list[response] = cls
        return super().__init_subclass__()

    @classmethod
    def create(cls, response_type: str, response: str) -> "SpontaneousResponse":
        return cls.__response_list[response_type](response)

    @classmethod
    def list(cls) -> List[str]:
        return list(cls.__response_list.keys())