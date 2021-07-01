# -*- coding: Utf-8 -*

from sys import stdout, stderr
from os import dup2
from random import choice as random_choice, randint
from uuid import UUID
from typing import Callable, List, NamedTuple, Optional, TextIO, Union

from .player import Player
from .vision import Coords, Tile
from .role import Role
from .position import Position
from .message import Message
from .resource import MetaResource, BaseResource, Food
from .elevation import Elevation, Requirements
from ..api_server.request import BroadcastRequest
from ..errors import ZappyError

INCANTATION_START = "I NEED SOME HELP!!!"
INCANTATION_PLAYER_COMING = "I'm coming !"
INCANTATION_PLAYER_HERE = "I'm here !"
INCANTATION_STARTED = "I don't need help anymore"
INCANTATION_PAUSED = "Wait I need to do something"
INCANTATION_REPORTED = "The number of player isn't correct"
INCANTATION_FAILED = "The setup for the incantation is wrong"


class SoughtResource(NamedTuple):
    resource: str
    tile: Tile
    pos: Position


class IncantationStart(ZappyError):
    def __init__(self, message: Message) -> None:
        super().__init__("An Incantation is requested")
        self.__message: Message = message

    @property
    def first_message(self) -> Message:
        return self.__message


class IncantationStopped(ZappyError):
    def __init__(self, was_in_place: bool) -> None:
        message: str
        if was_in_place:
            message = "Unfortunalety, the incantation was stopped"
        else:
            message = "The incantation started without me"
        super().__init__(message)


class AI:

    __required_food: Food = Food(30)
    __min_food: Food = Food(10)

    def __init__(self, player: Player, team: str, child: bool) -> None:
        self.__player: Player = player
        self.__team: str = team
        self.__last_action: Optional[Callable[..., None]] = None
        self.__child: bool = child
        self.__level_log: TextIO = open("./level.log", "a")
        self.__child_file: Optional[TextIO] = None
        if child:
            self.__child_file = open(f"fork-{self.__player.uuid}.log", "w")
            dup2(self.__child_file.fileno(), stdout.fileno())
            dup2(self.__child_file.fileno(), stderr.fileno())

    def __del__(self) -> None:
        self.__level_log.close()
        if self.__child_file is not None:
            self.__child_file.close()

    def start(self) -> None:
        self.__player.auto_inventory_checking(True)
        self.__player.look()
        self.__player.set_message_listener(self.__default_message_listener)
        self.__player.role = Role.NewPlayer
        self.__wait()
        print("AI setup finished.")

        print(f"New player {self.__player.uuid}: Current level: {self.__player.level}", file=self.__level_log)
        self.__level_log.flush()
        while self.__player.level < Elevation.max_level():
            self.__go_to_superior_level()
            print(f"{self.__player.uuid}: Current level: {self.__player.level}", file=self.__level_log)
            self.__level_log.flush()
            self.__fork_me()
            self.__player.update()
        while True:
            self.__fetch_sought_resources(self.__find_resource_in_vision(Food.get_name()))

    def __wait(self) -> None:
        while self.__player.doing_an_action():
            self.__player.update()

    def __wait_move(self) -> None:
        while self.__player.moving:
            self.__player.update()

    def __go_to_superior_level(self) -> None:
        superior_level: int = self.__player.level + 1
        while self.__player.level < superior_level:
            requirements: Requirements = Elevation.get_requirements(self.__player.level)
            if requirements.nb_players == 1:
                self.__go_to_superior_level_lonely(requirements)
            else:
                try:
                    self.__go_to_superior_level_with_other_players(requirements)
                except IncantationStart as e:
                    print("WAIT ! An incantion will start !")
                    self.__go_to_an_incantation_place(e.first_message)
            self.__player.set_message_listener(self.__default_message_listener)
        if self.__player.role == Role.NewPlayer:
            self.__player.role = Role.StoneSeeker

    def __fork_me(self) -> None:
        if not self.__child and self.__player.level < 7:
            self.__player.fork(1 if self.__player.level < 5 else 4)

    def __go_to_superior_level_lonely(self, requirements: Requirements) -> None:
        for resource in requirements.resources:
            print(f"Seeking {resource}({resource.amount})")
            self.__seek_resource(resource)
        self.__prepare_incantation(requirements)
        self.__player.start_incantation()
        self.__player.look()
        self.__wait()

    def __go_to_superior_level_with_other_players(self, requirements: Requirements) -> None:
        def custom_message_listener(message: Message) -> None:
            self.__default_message_listener(message)
            if message.team != self.__team or message.level != self.__player.level:
                return

            if message.body == INCANTATION_START:
                raise IncantationStart(message)

        def have_required_number(stone: BaseResource) -> bool:
            return self.__player.inventory.get(type(stone)) >= stone.amount

        def all_required_stone_is_gotten() -> bool:
            return all(have_required_number(stone) for stone in requirements.resources)

        def incantation_result(result: bool, at_start: bool) -> None:
            if result is False and at_start is True:
                self.__player.broadcast(INCANTATION_FAILED)

        self.__player.set_message_listener(custom_message_listener)

        all_resources: List[SoughtResource] = list()
        while not all_required_stone_is_gotten():
            if self.__check_for_food():
                continue
            all_resources.extend(self.__find_all_rare_resource_in_vision())
            for stone in requirements.resources:
                if not have_required_number(stone):
                    all_resources.extend(self.__find_resource_in_vision(stone))
            self.__fetch_sought_resources(all_resources)

        self.__prepare_incantation(requirements)
        self.__player.start_incantation(incantation_result)
        self.__player.look()
        self.__wait()

    def __go_to_an_incantation_place(self, first_message: Message) -> None:
        in_place: bool = False
        seeking_food: bool = False
        incantation_started: bool = False
        paused: bool = False
        player_uuid: UUID = first_message.uuid

        def incantation_listener(message: Message) -> None:
            nonlocal in_place, incantation_started, paused, player_uuid

            self.__default_message_listener(message)
            if message.team != self.__team or message.level != self.__player.level:
                return

            if message.uuid != player_uuid:
                if not paused:
                    return
                if message.body == INCANTATION_START:
                    player_uuid = message.uuid

            if message.body == INCANTATION_START and not in_place and not seeking_food and not self.__player.moving:
                paused = False
                if message.tile == 0:
                    self.__player.broadcast(INCANTATION_PLAYER_HERE)
                    in_place = True
                else:
                    self.__player.broadcast(INCANTATION_PLAYER_COMING)
                    self.__player.follow_sound(message)
                    self.__wait_move()
            elif message.body == INCANTATION_PAUSED:
                paused = True
                in_place = False
            elif message.body == INCANTATION_REPORTED:
                in_place = False
            elif message.body == INCANTATION_STARTED:
                if not in_place:
                    raise IncantationStopped(False)
                incantation_started = True
            elif message.body == INCANTATION_FAILED:
                self.__player.stop_waiting_incantation()

        def go_to_take_food() -> None:
            nonlocal seeking_food
            seeking_food = True
            self.__player.look()
            self.__wait()
            self.__seek_food()
            seeking_food = False
            self.__player.set_message_listener(incantation_listener)

        def go_to_incantation_place() -> None:
            while not in_place:
                if self.__check_for_food(seek=False):
                    go_to_take_food()
                self.__player.update()

        try:
            self.__player.set_message_listener(incantation_listener)
            self.__player.use_fetch_callback(False)
            incantation_listener(first_message)
            self.__player.wait_for_all_requests_to_be_done()
            while not incantation_started:
                go_to_incantation_place()
                print("OK, I'm here for the incantation")
                while not incantation_started and in_place:
                    if self.__player.inventory.get(Food) <= 2:
                        print("I can't wait anymore, I'm hungry !!!")
                        in_place = False
                        go_to_take_food()
                        break
                    self.__player.update()
            self.__player.auto_inventory_checking(False)
            self.__player.wait_for_all_requests_to_be_done()
            self.__player.assit_to_incantation()
            self.__wait()
        except IncantationStopped as e:
            print(e)
            self.__player.set_message_listener(self.__default_message_listener)
            if seeking_food:
                self.__seek_food()
        finally:
            self.__player.auto_inventory_checking(True)
            self.__player.use_fetch_callback(True)
            self.__player.look()
            self.__wait()

    def __seek_resource(self, resource: BaseResource) -> None:
        all_resources: List[SoughtResource] = list()

        if isinstance(resource, Food):
            return self.__seek_food()

        self.__last_action = None

        while self.__player.inventory.get(resource.name) < resource.amount:
            if self.__check_for_food(resource):
                continue

            all_resources.extend(self.__find_all_rare_resource_in_vision(resource))
            all_resources.extend(self.__find_resource_in_vision(resource))
            self.__fetch_sought_resources(all_resources)

    def __check_for_food(self, sought_stone: Optional[BaseResource] = None, *, seek: bool = True) -> bool:
        if self.__player.inventory.get(Food) < self.__min_food.amount:
            print(f"Missing food")
            if seek:
                self.__seek_food(sought_stone)
                print("I have sufficient food")
                if sought_stone is not None:
                    print(f"Seeking {sought_stone} again...")
            return True
        return False

    def __seek_food(self, sought_stone: Optional[BaseResource] = None) -> None:
        resources: List[SoughtResource] = list()
        while self.__player.inventory.get(Food) < self.__required_food.amount:
            resources.extend(self.__find_all_rare_resource_in_vision(sought_stone))
            resources.extend(self.__find_resource_in_vision(self.__required_food))
            if sought_stone is not None and self.__player.inventory.get(sought_stone.name) < sought_stone.amount:
                resources.extend(self.__find_resource_in_vision(sought_stone))
            self.__fetch_sought_resources(resources)

    def __find_resource_in_vision(self, resource: Union[str, BaseResource]) -> List[SoughtResource]:
        max_catch: Optional[int] = None
        if isinstance(resource, BaseResource):
            max_catch = resource.amount
            resource = resource.name
        all_resources: List[SoughtResource] = list()

        nb_resources: int = self.__player.inventory.get(resource)

        def has_sufficient_resources() -> bool:
            return max_catch is not None and nb_resources >= max_catch

        all_positions: List[Coords] = self.__player.vision.find(resource)
        if all_positions:
            print(f">> {resource} found")
            for p in all_positions:
                if has_sufficient_resources():
                    break
                tile: Tile = self.__player.vision.get_coord(p)
                all_resources.append(SoughtResource(resource, tile.copy(), self.__player.project_position(p.unit, p.divergence)))
                nb_resources += tile.get(resource)

        return all_resources

    def __find_all_rare_resource_in_vision(self, sought_stone: Optional[BaseResource] = None) -> List[SoughtResource]:
        all_resources: List[SoughtResource] = list()
        all_positions: List[SoughtResource]
        for rare_resource in MetaResource.get_rare_resources():
            if sought_stone == rare_resource:
                continue
            if self.__player.inventory.get(rare_resource) >= 3:
                continue
            all_positions = self.__find_resource_in_vision(rare_resource)
            if all_positions:
                print(f"-- YES! I found a {rare_resource} in {len(all_positions)} tile(s)")
                all_resources.extend(all_positions)
        return all_resources

    def __fetch_sought_resources(
        self, sought_resources: List[SoughtResource], success_callback: Optional[Callable[[str], None]] = None
    ) -> None:
        if not sought_resources:
            self.__change_position()
        else:
            for resource in sought_resources:
                self.__go_to_take_resource(resource, success_callback)
            sought_resources.clear()

    def __go_to_take_resource(
        self, sought_resource: SoughtResource, success_callback: Optional[Callable[[str], None]] = None
    ) -> None:
        resource: str = sought_resource.resource
        tile: Tile = sought_resource.tile
        position: Position = sought_resource.pos
        amount: int = tile[resource]
        self.__player.go_to_position(position)
        print(f"Nb {resource} in tile: {amount}")
        if (tile.index != 0 and "player" in tile) or (tile.index == 0 and tile["player"] > 1):
            print("There is an another player !!")
            self.__player.eject_from_this_tile()
        self.__player.take_object(resource, amount, success_callback=success_callback)
        self.__player.look()
        self.__wait()

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
        def custom_message_listener(message: Message) -> None:
            self.__default_message_listener(message)
            if message.team != self.__team or message.level != self.__player.level:
                return

            if message.body == INCANTATION_START:
                raise IncantationStart(message)

        self.__player.set_message_listener(custom_message_listener)
        turn: Optional[Callable[..., None]] = random_choice([self.__player.turn_left, self.__player.turn_right, None])
        if turn is not None:
            turn()
        self.__player.move_forward(randint(2, 10))
        self.__player.look()
        self.__wait()
        if self.__call_all_players(requirements) is False:
            self.__prepare_incantation(requirements)
            return
        self.__player.set_message_listener(self.__default_message_listener)
        tile: Tile = self.__player.vision.get(0, 0)
        while any(r not in requirements.resources and not isinstance(r, Food) for r in tile.resources):
            for resource in tile.resources:
                if isinstance(resource, Food):
                    continue
                self.__player.take_object(resource.name, resource.amount - requirements.get_number(resource.name))
            if not self.__player.taking_object():
                break
            self.__player.look()
            self.__wait()
            tile = self.__player.vision.get(0, 0)
        for resource in requirements.resources:
            self.__player.set_object_down(resource.name, resource.amount - tile[resource.name])

    def __call_all_players(self, requirements: Requirements) -> bool:
        broadcast_counter: int = 0
        max_broadcast: int = 30
        player_here: int = 1

        def message_listener(message: Message) -> None:
            nonlocal broadcast_counter, player_here
            self.__default_message_listener(message)

            if message.team != self.__team or message.level != self.__player.level:
                return
            if message.body == INCANTATION_PLAYER_COMING:
                broadcast_counter = 0
            elif message.body == INCANTATION_PLAYER_HERE:
                player_here += 1
                broadcast_counter = 0

        tile: Tile = self.__player.vision.get(0, 0)
        if requirements.nb_players == 1:
            return tile.nb_players == 1

        self.__player.set_message_listener(message_listener)
        while tile.nb_players < requirements.nb_players or player_here < requirements.nb_players:
            if not self.__player.broadcasting:
                if broadcast_counter == max_broadcast:
                    self.__player.broadcast(INCANTATION_REPORTED)
                    return False
                self.__player.broadcast(INCANTATION_START)
                broadcast_counter += 1
            if self.__check_for_food(seek=False):
                self.__player.broadcast(INCANTATION_PAUSED)
                broadcast_counter = 0
                player_here = 1
                self.__seek_food()
                continue
            self.__player.wait_for_nb_ticks(BroadcastRequest.get_process_time() + 10)
            self.__player.look()
            self.__wait()
            tile = self.__player.vision.get(0, 0)
            if tile.nb_players > requirements.nb_players:
                break
        if tile.nb_players > requirements.nb_players:
            self.__player.broadcast(INCANTATION_REPORTED)
            return False
        self.__player.broadcast(INCANTATION_STARTED)
        return True

    def __default_message_listener(self, message: Message) -> None:
        pass
