# -*- coding: Utf-8 -*

from typing import TypeVar, Union, NamedTuple

class Error(NamedTuple):
    message: str

class HelpError(Error):
    pass

T = TypeVar("T")

Result = Union[T, Error]