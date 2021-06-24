# -*- coding: Utf-8 -*

from time import time_ns


class Clock:
    def __init__(self) -> None:
        self.__actual: int = 0
        self.restart()

    def get_elapsed_time(self) -> int:
        return int((time_ns() - self.__actual) / (1000000))

    def elapsed_time(self, milliseconds: int, *, restart: bool = False) -> bool:
        if self.get_elapsed_time() < milliseconds:
            return False
        if restart:
            self.restart()
        return True

    def restart(self) -> None:
        self.__actual = time_ns()
