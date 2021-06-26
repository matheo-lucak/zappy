# -*- coding: Utf-8 -*

from random import choice as random_choice
from typing import Callable, List, Optional, Tuple

from .player import Player
from .team import Team
from .vision import Coords, Tile
from .role import Role
from .algorithm import Algorithm, Implementation
from .framerate import Framerate
from .message import Message
from .resource import MetaResource, BaseResource, Food
from .elevation import Elevation, Requirements
from ..utils.clock import Clock

NEW_PLAYER = "I'm new"
WELCOME = "Welcome"


class AI:

    __required_food: Food = Food(30)
    __min_food: Food = Food(10)

    def __init__(self, player: Player, team: Team, framerate: Framerate) -> None:
        self.__player: Player = player
        self.__team: Team = team
        self.__framerate: Framerate = framerate

    def start(self) -> Algorithm:
        return Algorithm(self.__implementation())

    def __implementation(self) -> Implementation:
        self.__player.set_message_listener(self.__message_listener)
        self.__player.broadcast(NEW_PLAYER)
        self.__player.role = Role.NewPlayer

        # clock: Clock = Clock()
        # while True:
        #     if clock.elapsed_time(1000, restart=True):
        #         print(f"Framerate: {self.__framerate.get()}fps")
        #         self.__player.broadcast("I'm alive")
        #         self.__player.move_forward()
        #     # if self.__player.moving_forward:
        #     #     print("Player moving")
        #     yield

        yield from self.__go_to_superior_level()

    def __go_to_superior_level(self) -> Implementation:
        superior_level: int = self.__player.level + 1
        while self.__player.level < superior_level:
            requirements: Requirements = Elevation.get_requirements(self.__player.level)
            if requirements.nb_players == 1:
                for resource in requirements.resources:
                    yield from self.__seek_resource(resource)
                print(self.__player.inventory)
                return
            yield
        yield
        # yield from self.__seek_resource()

    def __on_level_2(self) -> Implementation:
        yield
        # set role

    def __seek_resource(self, resource: BaseResource) -> Implementation:
        action: Callable[..., None]
        position: Coords
        last_action: Optional[Callable[..., None]] = None

        def go_to_take_resource(resource: str, unit: int, divergence: int) -> Implementation:
            if (unit, divergence) != (0, 0):
                self.__player.move_forward(abs(unit))
                if divergence < 0:
                    self.__player.turn_left()
                elif divergence > 0:
                    self.__player.turn_right()
                self.__player.move_forward(abs(divergence))
            while self.__player.moving:
                yield
            tile: Tile = self.__player.vision.get(unit, divergence)
            nb_resources_in_tile: int = tile[resource]
            print(f"Nb {resource} in tile: {nb_resources_in_tile}")
            self.__player.take_object(resource, nb_resources_in_tile)
            while self.__player.taking_object(resource):
                yield

        print(f"Seeking {resource}({resource.amount})...")
        while self.__player.inventory.get(resource) < resource.amount:
            if self.__player.inventory.get("food") < self.__min_food.amount and not isinstance(resource, Food):
                print(f"Missing food")
                yield from self.__seek_resource(self.__required_food)
                print(f"I have sufficient food")
                print(f"Seeking {resource} again...")
            all_positions: List[Coords] = self.__player.vision.find(resource)
            if not all_positions:
                for rare_resource in MetaResource.get_rare_resources():
                    all_positions = self.__player.vision.find(rare_resource)
                    if all_positions:
                        print(f"-- YES! I found {len(all_positions)} {rare_resource}{'s' if len(all_positions) > 1 else ''}")
                        for p in all_positions:
                            yield from go_to_take_resource(rare_resource, p.unit, p.divergence)
                        last_action = None

                if last_action is self.__player.move_forward:
                    action = random_choice([self.__player.move_forward, self.__player.turn_left, self.__player.turn_right])
                else:
                    action = self.__player.move_forward
                action()
                while self.__player.moving:
                    yield
            else:
                actual_nb: int = self.__player.inventory.get(resource)
                position = all_positions[0]
                yield from go_to_take_resource(resource.name, position.unit, position.divergence)
                if actual_nb < self.__player.inventory.get(resource):
                    print(f"--> {resource}: {self.__player.inventory.get(resource)}/{resource.amount}")
                last_action = None
            yield
        yield

    def __spy(self) -> Implementation:
        yield

    def __message_listener(self, message: Message) -> None:
        if message.team == self.__team.name:
            if message.body == NEW_PLAYER:
                self.__player.broadcast(WELCOME)
