# -*- coding: Utf-8 -*

from typing import Callable


class Framerate:
    def __init__(self, getter: Callable[[], int]) -> None:
        self.__getter: Callable[[], int] = getter

    def get(self) -> int:
        return self.__getter()
