# -*- coding: Utf-8 -*

from random import choice as random_choice
from re import compile as regex_compile
from typing import Callable, List, Optional, Tuple

from .player import Player
from .team import Team
from .vision import Coords, Tile
from .role import Role
from .position import Position
from .framerate import Framerate
from .message import Message
from .resource import MetaResource, BaseResource, Food
from .elevation import Elevation, Requirements

NEW_PLAYER = "I'm new"
WELCOME = "Welcome"

NEW_LEVEL_SEND = "I'm level {}"
NEW_LEVEL_RECV = regex_compile(r"I'm level +[0-9]+")
NEW_LEVEL_REPLY = "Level OK"


class AI:

    __required_food: Food = Food(30)
    __min_food: Food = Food(10)

    def __init__(self, player: Player, team: Team, framerate: Framerate) -> None:
        self.__player: Player = player
        self.__team: Team = team
        self.__framerate: Framerate = framerate
        self.__stone_sought: Optional[BaseResource] = None
        self.__last_action: Optional[Callable[..., None]] = None

    def start(self) -> None:
        self.__player.look()
        self.__player.check_inventory()
        self.__player.broadcast(NEW_PLAYER)
        self.__player.set_message_listener(self.__message_listener)
        self.__player.role = Role.NewPlayer
        self.__wait()
        print("AI setup finished.")

        while self.__player.level < Elevation.max_level():
            self.__go_to_superior_level()
            self.__player.update()
            return

    def __wait(self) -> None:
        while self.__player.doing_an_action():
            self.__player.update()

    def __go_to_superior_level(self) -> None:
        superior_level: int = self.__player.level + 1
        while self.__player.level < superior_level:
            requirements: Requirements = Elevation.get_requirements(self.__player.level)
            if requirements.nb_players == 1:
                self.__go_to_superior_level_lonely(requirements)
        if self.__player.role == Role.NewPlayer:
            self.__player.role = Role.StoneSeeker
        self.__player.broadcast(NEW_LEVEL_SEND.format(self.__player.level))

    def __go_to_superior_level_lonely(self, requirements: Requirements) -> None:
        self.__stone_sought = None
        for resource in requirements.resources:
            self.__stone_sought = resource
            print(f"Seeking {resource}({resource.amount})")
            while self.__player.inventory.get(resource) < resource.amount:
                self.__seek_resource(resource)
        self.__prepare_incantation(requirements)
        tile: Tile = self.__player.vision.get(0, 0)
        for resource in requirements.resources:
            self.__player.set_object_down(resource.name, resource.amount - tile[resource])
        self.__player.start_incantation()
        self.__wait()
        self.__player.look()
        self.__player.check_inventory()
        self.__wait()

    def __seek_resource(self, resource: BaseResource) -> None:
        action: Callable[..., None]
        position: Coords
        all_positions: List[Coords]
        tile: Tile

        self.__last_action = None
        def go_to_take_resource(resource: str, tile: Tile, position: Position) -> None:
            amount: int = tile[resource]
            self.__player.go_to_position(position)
            print(f"Nb {resource} in tile: {amount}")
            if (tile.index != 0 and "player" in tile) or (tile.index == 0 and tile["player"] > 1):
                print("There is an another player !!")
                self.__player.eject_from_this_tile()
            self.__player.take_object(resource, amount)
            self.__player.look()
            self.__player.check_inventory()
            self.__wait()
            if resource == Food.get_name():
                return
            if self.__stone_sought is not None and self.__stone_sought.name != resource:
                self.__player.broadcast(f"{resource} found")

        if self.__player.inventory.get(Food.get_name()) < self.__min_food.amount and not isinstance(resource, Food):
            print(f"Missing food")
            while self.__player.inventory.get(Food.get_name()) < self.__required_food.amount:
                self.__seek_resource(self.__required_food)
            print("I have sufficient food")
            print(f"Seeking {resource} again...")
            return

        positions_to_go: List[Tuple[str, Position, Tile]] = list()
        for rare_resource in MetaResource.get_rare_resources():
            if rare_resource == resource.name or (self.__stone_sought is not None and self.__stone_sought == resource):
                continue
            if self.__player.inventory.get(rare_resource) >= 3:
                continue
            all_positions = self.__player.vision.find(rare_resource)
            if all_positions:
                print(f"-- YES! I found a {rare_resource} in {len(all_positions)} tile(s)")
                for p in all_positions:
                    tile = self.__player.vision.get_coord(p)
                    positions_to_go.append((rare_resource, self.__player.project_position(p.unit, p.divergence), tile))

        if (
            isinstance(resource, Food)
            and self.__stone_sought is not None
            and self.__player.inventory.get(self.__stone_sought) < self.__stone_sought.amount
        ):
            for p in self.__player.vision.find(self.__stone_sought):
                tile = self.__player.vision.get_coord(p)
                positions_to_go.append((self.__stone_sought.name, self.__player.project_position(p.unit, p.divergence), tile))

        for resource_name, resource_pos, tile in positions_to_go:
            go_to_take_resource(resource_name, tile, resource_pos)
        all_positions = self.__player.vision.find(resource)
        if not all_positions:
            if self.__last_action is self.__player.move_forward:
                action = random_choice([self.__player.move_forward, self.__player.turn_left, self.__player.turn_right])
            else:
                action = self.__player.move_forward
            action()
            self.__player.look()
            self.__wait()
            self.__last_action = action
        else:
            print(f">> {resource} found")
            actual_nb: int = self.__player.inventory.get(resource)
            position = all_positions[0]
            tile = self.__player.vision.get_coord(position)
            go_to_take_resource(resource.name, tile, self.__player.project_position(position.unit, position.divergence))
            if actual_nb < self.__player.inventory.get(resource) and resource.amount > 0:
                print(f"--> {resource}: {self.__player.inventory.get(resource)}/{resource.amount}")

    def __prepare_incantation(self, requirements: Requirements) -> None:
        self.__player.move_forward(5)
        self.__player.look()
        self.__wait()
        tile: Tile = self.__player.vision.get(0, 0)
        while any(r not in requirements.resources and not isinstance(r, Food) for r in tile.resources):
            for resource in tile.resources:
                if isinstance(resource, Food):
                    continue
                self.__player.take_object(resource.name, resource.amount - requirements.get_number(resource.name))
            if not self.__player.taking_object():
                break
            self.__player.look()
            self.__player.check_inventory()
            self.__wait()
            tile = self.__player.vision.get(0, 0)

    def __message_listener(self, message: Message) -> None:
        self.__default_message_handler(message)

    def __default_message_handler(self, message: Message) -> None:
        if message.team == self.__team.name:
            if message.body == NEW_PLAYER:
                self.__player.broadcast(WELCOME)
            if NEW_LEVEL_RECV.match(message.body):
                self.__player.broadcast(NEW_LEVEL_REPLY)
