# -*- coding: Utf-8 -*

from typing import Callable, Dict, Generic, Optional, Tuple, Type, TypeVar, cast
from .response import Response


T = TypeVar("T", bound=Response)

class BaseRequest(Generic[T]):

    SEPARATOR: str = " "
    END_REQUEST: str = "\n"

    __response_class: Dict[Type["BaseRequest[T]"], Type[Response]] = dict()

    def __init_subclass__(cls, /, *, response: Type[Response] = Response) -> None:
        cls.__response_class[cls] = response
        return super().__init_subclass__()

    def __init__(self, command: str, *args: str, callback: Optional[Callable[[T], None]] = None) -> None:
        self.__command: str = command
        self.__args: Tuple[str, ...] = args
        self.__response: Optional[T] = None
        self.__callback: Optional[Callable[[T], None]] = callback

    def __repr__(self) -> str:
        return f"<{type(self).__name__}(command={self.__command}, args={self.__args})>"

    def __str__(self) -> str:
        return f"{self.__command}{self.SEPARATOR if self.__args else ''}{self.SEPARATOR.join(self.__args)}"

    @property
    def response(self) -> Optional[T]:
        return self.__response

    def set_response(self, response: str) -> None:
        ResponseClass: Type[Response] = self.__response_class.get(type(self), Response)
        self.__response = cast(T, ResponseClass(response))
        if callable(self.__callback):
            self.__callback(self.__response)

    def has_response(self) -> bool:
        return self.response is not None

Request = BaseRequest[Response]