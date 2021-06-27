# -*- coding: Utf-8 -*

from typing import TypeVar, Union, NamedTuple


class Error(NamedTuple):
    message: str


T = TypeVar("T")

Result = Union[T, Error]


class ZappyError(Exception):
    def __init__(self, message: str) -> None:
        super().__init__(message)
