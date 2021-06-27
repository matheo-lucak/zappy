# -*- coding: Utf-8 -*

from random import choice as random_choice
from typing import Callable, List, Optional, Tuple

from .player import Player
from .team import Team
from .vision import Coords, Tile
from .role import Role
from .position import Position
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
                yield from self.__start_incantation(requirements)
                return
            yield

    def __on_level_2(self) -> Implementation:
        yield
        # set role

    def __seek_resource(self, resource: BaseResource, *resources_to_get_with: BaseResource) -> Implementation:
        action: Callable[..., None]
        position: Coords
        all_positions: List[Coords]
        tile: Tile
        last_action: Optional[Callable[..., None]] = None

        def go_to_take_resource(resource: str, amount: int, position: Position) -> Implementation:
            self.__player.go_to_position(position)
            print(f"Nb {resource} in tile: {amount}")
            self.__player.take_object(resource, amount)
            self.__player.look()
            self.__player.check_inventory()
            while (
                self.__player.moving
                or self.__player.taking_object(resource)
                or self.__player.looking
                or self.__player.checking_inventory
            ):
                yield

        if resource.amount > 0:
            print(f"Seeking {resource}({resource.amount})...")
        else:
            print(f"Seeking {resource}...")
        while self.__player.inventory.get(resource) < resource.amount:
            if self.__player.inventory.get(self.__min_food.name) < self.__min_food.amount and not isinstance(resource, Food):
                print(f"Missing food")
                yield from self.__seek_resource(self.__required_food, resource)
                print("I have sufficient food")
                print(f"Seeking {resource} again...")
                continue

            positions_to_go: List[Tuple[str, Position, int]] = list()
            for rare_resource in MetaResource.get_rare_resources():
                if rare_resource == resource.name or any(r.name == rare_resource for r in resources_to_get_with):
                    continue
                if self.__player.inventory.get(rare_resource) >= 3:
                    continue
                all_positions = self.__player.vision.find(rare_resource)
                if all_positions:
                    print(f"-- YES! I found a {rare_resource} in {len(all_positions)} tiles")
                    for p in all_positions:
                        tile = self.__player.vision.get_coord(p)
                        positions_to_go.append(
                            (rare_resource, self.__player.project_position(p.unit, p.divergence), tile[rare_resource])
                        )

            for search in resources_to_get_with:
                if search.amount > 0 and self.__player.inventory.get(search) >= search.amount:
                    continue
                for p in self.__player.vision.find(search):
                    tile = self.__player.vision.get_coord(p)
                    positions_to_go.append((search.name, self.__player.project_position(p.unit, p.divergence), tile[search]))

            for resource_name, resource_pos, amount in positions_to_go:
                yield from go_to_take_resource(resource_name, amount, resource_pos)
            all_positions = self.__player.vision.find(resource)
            if not all_positions:
                if last_action is self.__player.move_forward:
                    action = random_choice([self.__player.move_forward, self.__player.turn_left, self.__player.turn_right])
                else:
                    action = self.__player.move_forward
                action()
                self.__player.look()
                while self.__player.moving or self.__player.looking:
                    yield
                last_action = action
            else:
                print(f">> {resource} found")
                actual_nb: int = self.__player.inventory.get(resource)
                position = all_positions[0]
                tile = self.__player.vision.get_coord(position)
                yield from go_to_take_resource(
                    resource.name, tile[resource], self.__player.project_position(position.unit, position.divergence)
                )
                if actual_nb < self.__player.inventory.get(resource) and resource.amount > 0:
                    print(f"--> {resource}: {self.__player.inventory.get(resource)}/{resource.amount}")
            yield

    def __start_incantation(self, requirements: Requirements) -> Implementation:
        self.__player.move_forward(5)
        self.__player.look()
        while self.__player.moving or self.__player.looking:
            yield
        if requirements.nb_players == 1:
            tile: Tile = self.__player.vision.get(0, 0)
            print(repr(tile))
            while any(r not in requirements.resources and not isinstance(r, Food) for r in tile.resources):
                for tile in self.__player.vision.tiles:
                    for resource in tile.resources:
                        if isinstance(resource, Food):
                            continue
                        self.__player.take_object(
                            resource.name, resource.amount - Elevation.get_required_number(self.__player.level, resource.name)
                        )
                self.__player.look()
                self.__player.check_inventory()
                while self.__player.taking_object() or self.__player.looking or self.__player.checking_inventory:
                    yield
            for resource in requirements.resources:
                self.__player.set_object_down(resource.name, resource.amount - tile[resource])
            self.__player.look()
            self.__player.check_inventory()
            while self.__player.setting_object_down() or self.__player.looking or self.__player.checking_inventory:
                yield
            print(self.__player.inventory)
            print(self.__player.vision)
        yield

    def __spy(self) -> Implementation:
        yield

    def __message_listener(self, message: Message) -> None:
        if message.team == self.__team.name:
            if message.body == NEW_PLAYER:
                self.__player.broadcast(WELCOME)
