# -*- coding: Utf-8 -*

from typing import Iterable, Iterator

Implementation = Iterable[None]


class Algorithm(Iterator[None]):
    def __init__(self, implementation: Implementation) -> None:
        super().__init__()
        self.__impl: Iterator[None] = iter(implementation)

    def __iter__(self) -> Iterator[None]:
        return self

    def __next__(self) -> None:
        return next(self.__impl)
