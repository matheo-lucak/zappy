# -*- coding: Utf-8 -*

from sys import stderr
from typing import Any


class Logger:

    __verbose: int = 0

    @classmethod
    def get_verbose_level(cls) -> int:
        return cls.__verbose

    @classmethod
    def set_verbose_level(cls, value: int) -> None:
        cls.__verbose = max(value, 0)

    @classmethod
    def print(cls, required_level: int, *args: Any, **kwargs: Any) -> None:
        if cls.__verbose >= required_level:
            print(*args, **kwargs, file=stderr)
