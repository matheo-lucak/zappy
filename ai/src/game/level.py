# -*- coding: Utf-8 -*

from .elevation import Elevation


class Level:
    def __init__(self) -> None:
        self.__value: int = 1

    @property
    def value(self) -> int:
        return self.__value

    @value.setter
    def value(self, v: int) -> None:
        self.__value = max(int(v), 1)

    @staticmethod
    def max() -> int:
        return Elevation.max_level()
