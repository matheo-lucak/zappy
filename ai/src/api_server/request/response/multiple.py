# -*- coding: Utf-8 -*

from typing import Any, Tuple

from .base import Response


class MultiResponse(Response):
    def __init_subclass__(cls, /, *, nb_responses: int, wait_for_all: bool) -> None:
        super().__init_subclass__()
        if nb_responses < 2:
            raise ValueError("nb_responses must be a positive integer greather than 1")
        setattr(cls, "__nb_responses__", nb_responses)
        setattr(cls, "__wait_all__", wait_for_all)

    def __new__(cls, response: str, *other_responses: str, **kwargs: Any) -> Any:
        if cls is MultiResponse:
            raise TypeError(f"{cls.__name__} can't be instantiated")
        nb_responses: int = len(other_responses) + 1
        if nb_responses > cls.nb_responses() or (cls.wait_for_all() and nb_responses < cls.nb_responses()):
            raise ValueError(f"Number of response isn't correct: actual=`{nb_responses}`, expected=`{cls.nb_responses()}`")
        return super().__new__(cls)

    def __init__(self, *responses: str) -> None:
        super().__init__(self.END_RESPONSE.join(responses))
        self.__responses: Tuple[str, ...] = responses

    @property
    def list(self) -> Tuple[str, ...]:
        return self.__responses

    @property
    def complete(self) -> bool:
        return len(self.__responses) == self.nb_responses()

    @classmethod
    def nb_responses(cls) -> int:
        if cls is MultiResponse:
            raise AttributeError(f"Base class {cls.__name__} does not have this attribute")
        return int(getattr(cls, "__nb_responses__"))

    @classmethod
    def wait_for_all(cls) -> bool:
        if cls is MultiResponse:
            raise AttributeError(f"Base class {cls.__name__} does not have this attribute")
        return bool(getattr(cls, "__wait_all__"))
