# -*- coding: Utf-8 -*

from .player import Player
from .team import Team
from .algorithm import Algorithm, Implementation
from .framerate import Framerate
from ..utils.clock import Clock


class AI:
    def __init__(self, player: Player, team: Team, framerate: Framerate) -> None:
        self.__player: Player = player
        self.__team: Team = team
        self.__framerate: Framerate = framerate

    def start(self) -> Algorithm:
        return Algorithm(self.__implementation())

    def __implementation(self) -> Implementation:
        clock: Clock = Clock()
        while True:
            if clock.elapsed_time(1000, restart=True):
                print(f"Framerate: {self.__framerate.get()}fps")
                self.__player.broadcast("I'm alive")
                self.__player.move_forward()
            # if self.__player.moving_forward:
            #     print("Player moving")
            yield
