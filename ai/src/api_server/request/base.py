# -*- coding: Utf-8 -*

from typing import Any, Callable, Generic, Optional, Tuple, Type, TypeVar
from .response import Response, SpontaneousResponse


T = TypeVar("T", bound=Response)
ResponseCallback = Callable[[T], None]


class BaseRequest(Generic[T]):

    SEPARATOR: str = " "
    END_REQUEST: str = "\n"

    def __init_subclass__(cls) -> None:
        super().__init_subclass__()
        response: Type[T] = getattr(getattr(cls, "__orig_bases__")[0], "__args__")[0]
        if issubclass(response, SpontaneousResponse):
            raise TypeError("A request cannot have a spontaneous response.")
        setattr(cls, "__response_class__", response)

    def __new__(cls, *args: Any, **kwargs: Any) -> Any:
        if cls is BaseRequest:
            raise TypeError(f"{cls.__name__} can't be instantiated")
        return super().__new__(cls)

    def __init__(self, command: str, *args: str, callback: Optional[ResponseCallback[T]] = None) -> None:
        self.__command: str = command
        self.__args: Tuple[str, ...] = args
        self.__response: Optional[T] = None
        self.__callback: Optional[ResponseCallback[T]] = callback

    def __repr__(self) -> str:
        return f"<{type(self).__name__}(command={self.__command}, args={self.__args})>"

    def __str__(self) -> str:
        return f"{self.__command}{self.SEPARATOR if self.__args else ''}{self.SEPARATOR.join(self.__args)}"

    @property
    def command(self) -> str:
        return self.__command

    @property
    def args(self) -> Tuple[str, ...]:
        return self.__args

    @property
    def response(self) -> Optional[T]:
        return self.__response

    def set_response(self, response: str) -> None:
        ResponseClass: Type[T] = getattr(type(self), "__response_class__")
        self.__response = ResponseClass(response)
        if callable(self.__callback):
            self.__callback(self.__response)

    def has_response(self) -> bool:
        return self.response is not None


class Request(BaseRequest[Response]):
    pass
