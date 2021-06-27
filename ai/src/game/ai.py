# -*- coding: Utf-8 -*

from random import choice as random_choice
from re import compile as regex_compile, Match
from typing import Callable, Dict, List, NamedTuple, Optional, Pattern, Tuple, Union

from .player import MessageListener, Player
from .team import Team
from .vision import Coords, Tile
from .role import Role
from .position import Position
from .framerate import Framerate
from .message import Message
from .resource import MetaResource, BaseResource, Food
from .elevation import Elevation, Requirements
from ..errors import ZappyError

NEW_PLAYER = "I'm new"
WELCOME = "Welcome"

NEW_LEVEL_SEND = "I'm level {}"
NEW_LEVEL_RECV = regex_compile(r"I'm level +[0-9]+")
NEW_LEVEL_REPLY = "Level OK"

STONE_FOUND_SEND = "{} found"
STONE_FOUND_RECV = regex_compile(r"(\w+) found")
STONE_SOUGHT_SEND = "{} sought"
STONE_SOUGHT_RECV = regex_compile(r"(\w+) sought")
STONE_ALREADY_TAKEN_SEND = "{} already taken"
STONE_ALREADY_TAKEN_RECV = regex_compile(r"(\w+) already taken")


def match_message(message: str, prefixes: Optional[Union[str, Tuple[str, ...]]] = None) -> Optional[Match[str]]:
    match: Optional[Match[str]] = None

    for name, var in globals().items():
        if prefixes is not None and not name.startswith(prefixes):
            continue
        if isinstance(var, Pattern):
            match = var.match(message)
            if match is not None:
                break

    return match


class SoughtResource(NamedTuple):
    resource: str
    tile: Tile
    pos: Position


class AI:

    __required_food: Food = Food(30)
    __min_food: Food = Food(10)

    def __init__(self, player: Player, team: Team, framerate: Framerate) -> None:
        self.__player: Player = player
        self.__team: Team = team
        self.__framerate: Framerate = framerate
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

    def __wait(self) -> None:
        while self.__player.doing_an_action():
            self.__player.update()

    def __go_to_superior_level(self) -> None:
        superior_level: int = self.__player.level + 1
        while self.__player.level < superior_level:
            requirements: Requirements = Elevation.get_requirements(self.__player.level)
            if requirements.nb_players == 1:
                self.__go_to_superior_level_lonely(requirements)
            else:
                self.__go_to_superior_level_with_other_players(requirements)
        if self.__player.role == Role.NewPlayer:
            self.__player.role = Role.StoneSeeker
        self.__player.broadcast(NEW_LEVEL_SEND.format(self.__player.level))

    def __go_to_superior_level_lonely(self, requirements: Requirements) -> None:
        for resource in requirements.resources:
            print(f"Seeking {resource}({resource.amount})")
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

    def __go_to_superior_level_with_other_players(self, requirements: Requirements) -> None:
        # nb_players: int = requirements.nb_players - 1

        gotten_stones: Dict[str, BaseResource] = {r.name: MetaResource.create(r.name) for r in requirements.resources}

        def custom_message_listener(message: Message) -> None:
            self.__default_message_handler(message)
            if message.team != self.__team.name:
                return
            stone: str = str()
            match: Optional[Match[str]] = match_message(message.body, prefixes="STONE")
            if match is None:
                return

            # Count stones from messages

        def all_required_stone_is_gotten() -> bool:
            return all(self.__player.inventory.get(stone) >= stone.amount for stone in requirements.resources)

        actual_message_listener: Optional[MessageListener] = self.__player.set_message_listener(custom_message_listener)

        while not all_required_stone_is_gotten():
            if self.__check_for_food():
                continue
            all_resources: List[SoughtResource] = self.__find_all_rare_resource_in_vision()
            for stone in requirements.resources:
                all_resources.extend(self.__find_resource_in_vision(stone))
            if not all_resources:
                self.__change_position()
            else:
                for sought_resource in all_resources:
                    self.__go_to_take_resource(sought_resource)
            # Register gotten stones

        # Elevation setup
        raise ZappyError("Force end")

        self.__player.set_message_listener(actual_message_listener)

    def __seek_resource(self, resource: BaseResource) -> None:
        all_resources: List[SoughtResource] = list()

        if isinstance(resource, Food):
            return self.__seek_food()

        self.__last_action = None

        while self.__player.inventory.get(resource) < resource.amount:
            if self.__check_for_food(resource):
                continue

            all_resources = self.__find_all_rare_resource_in_vision(resource)
            all_resources.extend(self.__find_resource_in_vision(resource))
            if not all_resources:
                self.__change_position()
            else:
                for sought_resource in all_resources:
                    self.__go_to_take_resource(sought_resource)

    def __check_for_food(self, sought_stone: Optional[BaseResource] = None) -> bool:
        if self.__player.inventory.get(Food.get_name()) < self.__min_food.amount:
            print(f"Missing food")
            self.__seek_food(sought_stone)
            print("I have sufficient food")
            print(f"Seeking {sought_stone} again...")
            return True
        return False

    def __seek_food(self, sought_stone: Optional[BaseResource] = None) -> None:
        resources: List[SoughtResource] = list()
        while self.__player.inventory.get(Food.get_name()) < self.__required_food.amount:
            resources = self.__find_all_rare_resource_in_vision(sought_stone)
            resources.extend(self.__find_resource_in_vision(self.__required_food))
            if sought_stone is not None and self.__player.inventory.get(sought_stone) < sought_stone.amount:
                resources.extend(self.__find_resource_in_vision(sought_stone))
            if not resources:
                self.__change_position()
            else:
                for sought_resource in resources:
                    self.__go_to_take_resource(sought_resource)

    def __find_resource_in_vision(self, resource: Union[str, BaseResource]) -> List[SoughtResource]:
        if isinstance(resource, BaseResource):
            resource = resource.name
        all_resources: List[SoughtResource] = list()

        all_positions: List[Coords] = self.__player.vision.find(resource)
        if all_positions:
            print(f">> {resource} found")
            for p in all_positions:
                tile: Tile = self.__player.vision.get_coord(p)
                all_resources.append(SoughtResource(resource, tile, self.__player.project_position(p.unit, p.divergence)))

        return all_resources

    def __find_all_rare_resource_in_vision(self, sought_stone: Optional[BaseResource] = None) -> None:
        all_resources: List[SoughtResource] = list()
        all_positions: List[SoughtResource]
        for rare_resource in MetaResource.get_rare_resources():
            if (sought_stone == rare_resource):
                continue
            if self.__player.inventory.get(rare_resource) >= 3:
                continue
            all_positions = self.__find_resource_in_vision(rare_resource)
            if all_positions:
                print(f"-- YES! I found a {rare_resource} in {len(all_positions)} tile(s)")
                all_resources.extend(all_positions)
        return all_resources

    def __go_to_take_resource(self, sought_resource: SoughtResource) -> None:
        resource: str = sought_resource.resource
        tile: Tile = sought_resource.tile
        position: Position = sought_resource.pos
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
        self.__player.broadcast(STONE_FOUND_SEND.format(resource))

    def __change_position(self) -> None:
        action: Callable[..., None]
        if self.__last_action is self.__player.move_forward:
            action = random_choice([self.__player.move_forward, self.__player.turn_left, self.__player.turn_right])
        else:
            action = self.__player.move_forward
        action()
        self.__player.look()
        self.__wait()
        self.__last_action = action

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
