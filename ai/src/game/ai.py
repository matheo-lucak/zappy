# -*- coding: Utf-8 -*

from time import time_ns
from typing import Iterator
from .player import Player
from .algorithm import Algorithm, Implementation


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


class AI:
    def __init__(self, player: Player) -> None:
        self.__player: Player = player

    def start(self) -> Algorithm:
        return Algorithm(self.__implementation())

    def __implementation(self) -> Implementation:
        clock: Clock = Clock()
        while True:
            if clock.elapsed_time(1000, restart=True):
                self.__player.broadcast("I'm alive")
                self.__player.move_forward()
            # if self.__player.moving_forward:
            #     print("Player moving")
            yield
