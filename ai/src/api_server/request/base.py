# -*- coding: Utf-8 -*

from typing import Any, Callable, Generic, Optional, Tuple, Type, TypeVar, cast

from .response import Response, SpontaneousResponse, MultiResponse


T = TypeVar("T", bound=Response)
ResponseCallback = Callable[[T], None]


class MetaRequest(type):
    def __call__(cls, *args: Any, **kwds: Any) -> Any:
        if cls is BaseRequest:
            raise TypeError(f"{cls.__name__} can't be instantiated")
        return super().__call__(*args, **kwds)


class BaseRequest(Generic[T], metaclass=MetaRequest):

    SEPARATOR: str = " "
    END_REQUEST: str = "\n"

    def __init_subclass__(cls, /, *, process_time: int) -> None:
        super().__init_subclass__()
        response: Type[T] = getattr(getattr(cls, "__orig_bases__")[0], "__args__")[0]
        if issubclass(response, SpontaneousResponse):
            raise TypeError("A request cannot have a spontaneous response.")
        if response is MultiResponse:
            raise TypeError("Cannot use base class MultiResponse as response class.")
        setattr(cls, "__response_class__", response)
        if process_time < 0:
            raise ValueError(f"Process time can't be a negative number: {process_time}")
        setattr(cls, "__process_time__", int(process_time))

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

    @response.setter
    def response(self, rp: T) -> None:
        if not isinstance(rp, Response):
            raise TypeError(f"Not a Response type")
        self.__response = rp
        if callable(self.__callback):
            self.__callback(rp)

    @classmethod
    def get_response_type(cls) -> Type[T]:
        return cast(Type[T], getattr(cls, "__response_class__"))

    @classmethod
    def get_process_time(cls) -> int:
        return int(getattr(cls, "__process_time__"))

    @classmethod
    def get_real_process_time(cls, framerate: float) -> float:
        return cls.get_process_time() / framerate if framerate > 0 else 0


class Request(BaseRequest[Response], process_time=0):
    pass
