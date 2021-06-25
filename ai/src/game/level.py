# -*- coding: Utf-8 -*

from .elevation import ELEVATION_SECRETS


class Level:
    def __init__(self) -> None:
        self.__value: int = 1

    @property
    def value(self) -> int:
        return self.__value

    @staticmethod
    def max() -> int:
        return max(ELEVATION_SECRETS.keys()) + 1
