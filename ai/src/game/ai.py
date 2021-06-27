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

NEW_PLAYER = "I'm new"
WELCOME = "Welcome"


class AI:

    __required_food: Food = Food(30)
    __min_food: Food = Food(10)

    def __init__(self, player: Player, team: Team, framerate: Framerate) -> None:
        self.__player: Player = player
        self.__team: Team = team
        self.__framerate: Framerate = framerate
        self.__resource_sought: Optional[BaseResource] = None

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
                    self.__resource_sought = resource
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

        def go_to_take_resource(resource: str, tile: Tile, position: Position) -> Implementation:
            amount: int = tile[resource]
            self.__player.go_to_position(position)
            print(f"Nb {resource} in tile: {amount}")
            if (tile.index != 0 and "player" in tile) or (tile.index == 0 and tile["player"] > 1):
                print("There is an another player !!")
                self.__player.eject_from_this_tile()
            self.__player.take_object(resource, amount)
            self.__player.look()
            self.__player.check_inventory()
            while self.__player.doing_an_action():
                yield
            if resource == Food.get_name():
                return
            if self.__resource_sought is not None and self.__resource_sought.name != resource:
                self.__player.broadcast(f"{resource} found")

        if resource.amount > 0:
            print(f"Seeking {resource}({resource.amount})...")
        else:
            print(f"Seeking {resource}...")
        while self.__player.inventory.get(resource) < resource.amount:
            if self.__player.inventory.get(Food.get_name()) < self.__min_food.amount and not isinstance(resource, Food):
                print(f"Missing food")
                yield from self.__seek_resource(self.__required_food, resource)
                print("I have sufficient food")
                print(f"Seeking {resource} again...")
                continue

            positions_to_go: List[Tuple[str, Position, Tile]] = list()
            for rare_resource in MetaResource.get_rare_resources():
                if rare_resource == resource.name or any(r.name == rare_resource for r in resources_to_get_with):
                    continue
                if self.__player.inventory.get(rare_resource) >= 3:
                    continue
                all_positions = self.__player.vision.find(rare_resource)
                if all_positions:
                    print(f"-- YES! I found a {rare_resource} in {len(all_positions)} tile(s)")
                    for p in all_positions:
                        tile = self.__player.vision.get_coord(p)
                        positions_to_go.append((rare_resource, self.__player.project_position(p.unit, p.divergence), tile))

            for search in resources_to_get_with:
                if search.amount > 0 and self.__player.inventory.get(search) >= search.amount:
                    continue
                for p in self.__player.vision.find(search):
                    tile = self.__player.vision.get_coord(p)
                    positions_to_go.append((search.name, self.__player.project_position(p.unit, p.divergence), tile))

            for resource_name, resource_pos, tile in positions_to_go:
                yield from go_to_take_resource(resource_name, tile, resource_pos)
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
                    resource.name, tile, self.__player.project_position(position.unit, position.divergence)
                )
                if actual_nb < self.__player.inventory.get(resource) and resource.amount > 0:
                    print(f"--> {resource}: {self.__player.inventory.get(resource)}/{resource.amount}")
            yield

    def __start_incantation(self, requirements: Requirements) -> Implementation:
        self.__player.move_forward(5)
        self.__player.look()
        while self.__player.moving_forward or self.__player.looking:
            yield
        tile: Tile = self.__player.vision.get(0, 0)
        if requirements.nb_players == 1:
            while any(r not in requirements.resources and not isinstance(r, Food) for r in tile.resources):
                for resource in tile.resources:
                    if isinstance(resource, Food):
                        continue
                    self.__player.take_object(resource.name, resource.amount - requirements.get_number(resource.name))
                self.__player.look()
                self.__player.check_inventory()
                while self.__player.doing_an_action():
                    yield
            for resource in requirements.resources:
                self.__player.set_object_down(resource.name, resource.amount - tile[resource])
            self.__player.look()
            self.__player.check_inventory()
            while self.__player.doing_an_action():
                yield
        yield

    def __spy(self) -> Implementation:
        yield

    def __message_listener(self, message: Message) -> None:
        if message.team == self.__team.name:
            if message.body == NEW_PLAYER:
                self.__player.broadcast(WELCOME)
