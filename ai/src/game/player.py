# -*- coding: Utf-8 -*

from typing import Any, Callable, Dict, List, Optional, Type, NoReturn

from .inventory import Inventory
from .vision import Vision
from .level import Level
from .message import Message, MessageError
from .role import Role
from .position import Position, Orientation
from .action import BaseAction
from ..api_server import APIServer
from ..api_server.request.broadcast import BroadcastRequest
from ..api_server.request.eject import EjectRequest, EjectResponse
from ..api_server.request.forward import ForwardRequest
from ..api_server.request.incantation import IncantationRequest, IncantationResponse
from ..api_server.request.inventory import InventoryRequest, InventoryResponse
from ..api_server.request.look import LookRequest, LookResponse
from ..api_server.request.left import LeftRequest
from ..api_server.request.right import RightRequest
from ..api_server.request.set_object_down import SetObjectDownRequest, SetObjectDownResponse
from ..api_server.request.take_object import TakeObjectRequest, TakeObjectResponse
from ..api_server.request.response.spontaneous import SpontaneousResponse, DeadResponse, MessageResponse
from ..api_server.request.response.exceptions import ResponseError
from ..errors import ZappyError


class PlayerDeadError(ZappyError):
    def __init__(self) -> None:
        super().__init__("I'm dying...!")


MessageListener = Callable[[Message], None]


class Action(BaseAction):
    checking_inventory: int
    forwarding: int
    looking: int
    turning_left: int
    turning_right: int
    ejecting: int
    taking_resource: int
    setting_resource: int
    elevating: int


class Player:
    def __init__(self, team_name: str, api: APIServer) -> None:
        self.__team: str = team_name
        self.__inventory: Inventory = Inventory()
        self.__vision: Vision = Vision()
        self.__level: Level = Level()
        self.__role: Role = Role.NewPlayer
        self.__api: APIServer = api
        self.__message_listener: Optional[MessageListener] = None
        self.__pos: Position = Position(0, 0)
        self.__orientation: Orientation = Orientation.North

        self.__action: Action = Action()

        self.__taking_resource: Dict[str, int] = dict()
        self.__setting_resource: Dict[str, int] = dict()

        self.__api.set_spontaneous_response_handler(self.__handle_spontaneous_responses)

    def update(self) -> None:
        self.__api.fetch()

    def look(self) -> None:
        def look_handler(response: LookResponse) -> None:
            self.__vision.update(response)
            print("Vision up-to-date")
            print("->", self.__vision)
            self.__action.looking -= 1

        self.__action.looking += 1
        self.__api.send(LookRequest(look_handler))

    @property
    def looking(self) -> int:
        return self.__action.looking

    def check_inventory(self) -> None:
        def inventory_handler(response: InventoryResponse) -> None:
            self.__inventory.update(response)
            print("Inventory up-to-date")
            print("->", self.__inventory)
            self.__action.checking_inventory -= 1

        self.__action.checking_inventory += 1
        self.__api.send(InventoryRequest(inventory_handler))

    @property
    def checking_inventory(self) -> int:
        return self.__action.checking_inventory

    @property
    def moving(self) -> int:
        return self.moving_forward + self.turning_left + self.turning_right

    def move_forward(self, nb_times: int = 1) -> None:
        def forward_handler() -> None:
            print("Move forward action completed")
            self.__action.forwarding -= 1
            new_pos: Dict[Orientation, Position] = {
                Orientation.North: Position(self.pos.x, self.pos.y + 1),
                Orientation.South: Position(self.pos.x, self.pos.y - 1),
                Orientation.East: Position(self.pos.x + 1, self.pos.y),
                Orientation.West: Position(self.pos.x - 1, self.pos.y),
            }
            self.__pos = new_pos[self.__orientation]

        for _ in range(nb_times):
            print("Moving forward...")
            self.__action.forwarding += 1
            self.__api.send(ForwardRequest(lambda rp: forward_handler()))

    @property
    def moving_forward(self) -> int:
        return self.__action.forwarding

    def turn_left(self, nb_times: int = 1) -> None:
        def turn_handler() -> None:
            print("Left rotation completed")
            self.__action.turning_left -= 1
            new_orientation: Dict[Orientation, Orientation] = {
                Orientation.North: Orientation.West,
                Orientation.West: Orientation.South,
                Orientation.South: Orientation.East,
                Orientation.East: Orientation.North,
            }
            self.__orientation = new_orientation[self.__orientation]

        for _ in range(nb_times):
            print("Turning 90deg left...")
            self.__action.turning_left += 1
            self.__api.send(LeftRequest(lambda rp: turn_handler()))

    @property
    def turning_left(self) -> int:
        return self.__action.turning_left

    def turn_right(self, nb_times: int = 1) -> None:
        def turn_handler() -> None:
            print("Right rotation completed")
            self.__action.turning_right -= 1
            new_orientation: Dict[Orientation, Orientation] = {
                Orientation.North: Orientation.East,
                Orientation.East: Orientation.South,
                Orientation.South: Orientation.West,
                Orientation.West: Orientation.North,
            }
            self.__orientation = new_orientation[self.__orientation]

        for _ in range(nb_times):
            print("Turning 90deg right...")
            self.__action.turning_right += 1
            self.__api.send(RightRequest(lambda rp: turn_handler()))

    @property
    def turning_right(self) -> int:
        return self.__action.turning_right

    def go_to_position(self, position: Position) -> None:
        if position == self.pos:
            return

        x_diff: int = 0
        y_diff: int = 0

        if self.__orientation == Orientation.North:
            x_diff = position.x - self.pos.x
            y_diff = position.y - self.pos.y
        elif self.__orientation == Orientation.South:
            x_diff = self.pos.x - position.x
            y_diff = self.pos.y - position.y
        elif self.__orientation == Orientation.East:
            x_diff = self.pos.y - position.y
            y_diff = position.x - self.pos.x
        elif self.__orientation == Orientation.West:
            x_diff = position.y - self.pos.y
            y_diff = self.pos.x - position.x
        if x_diff == 0:
            if y_diff < 0:
                self.turn_left(2)
            self.move_forward(abs(y_diff))
        else:
            turn: Callable[..., None] = self.turn_left if x_diff < 0 else self.turn_right
            if y_diff > 0:
                self.move_forward(y_diff)
                turn()
                self.move_forward(abs(x_diff))
            else:
                turn()
                self.move_forward(abs(x_diff))
                if y_diff != 0:
                    turn()
                    self.move_forward(abs(y_diff))

    def broadcast(self, message: str) -> None:
        message = message.strip()
        if len(message) == 0:
            return

        message = f"{self.__team}: lvl {self.level}({self.role.value}): {message}"
        print(f"Broadcasting: {repr(message)}")
        self.__api.send(BroadcastRequest(message), have_priority=True)

    def set_message_listener(self, callback: Optional[MessageListener]) -> Optional[MessageListener]:
        former_listener: Optional[MessageListener] = self.__message_listener
        self.__message_listener = callback
        return former_listener

    def take_object(self, resource: str, number: int = 1) -> None:
        def take_handler(response: TakeObjectResponse) -> None:
            print(f"{repr(resource)}: {'taken' if response.ok else 'not taken'}")
            self.__action.taking_resource -= 1
            self.__taking_resource[resource] = self.taking_object(resource) - 1
            if self.__taking_resource[resource] < 1:
                self.__taking_resource.pop(resource)

        for _ in range(number):
            print(f"Taking {resource}...")
            self.__action.taking_resource += 1
            self.__taking_resource[resource] = self.taking_object(resource) + 1
            self.__api.send(TakeObjectRequest(resource, callback=take_handler))

    def taking_object(self, resource: Optional[str] = None) -> int:
        if resource is None:
            return self.__action.taking_resource
        return self.__taking_resource.get(resource, 0)

    def set_object_down(self, resource: str, number: int = 1) -> None:
        def set_handler(response: SetObjectDownResponse) -> None:
            print(f"{repr(resource)}: {'set down' if response.ok else 'not set down'}")
            self.__action.setting_resource -= 1
            self.__setting_resource[resource] = self.setting_object_down(resource) - 1
            if self.__setting_resource[resource] < 1:
                self.__setting_resource.pop(resource)

        for _ in range(number):
            print(f"Setting {resource} down...")
            self.__action.setting_resource += 1
            self.__setting_resource[resource] = self.setting_object_down(resource) + 1
            self.__api.send(SetObjectDownRequest(resource, callback=set_handler))

    def setting_object_down(self, resource: Optional[str] = None) -> int:
        if resource is None:
            return self.__action.setting_resource
        return self.__setting_resource.get(resource, 0)

    def eject_from_this_tile(self) -> None:
        def eject_handler(response: EjectResponse) -> None:
            print(f"Ejected: {response.ok}. Waiting for vision update...")
            self.__action.ejecting -= 1

        self.__action.ejecting += 1
        self.__api.send(EjectRequest(eject_handler))

    @property
    def ejecting_player(self) -> int:
        return self.__action.ejecting

    def start_incantation(self) -> None:
        def incantation_handler(response: IncantationResponse) -> None:
            if response.result is None:
                print("Elevation underway")
                return
            if response.result is False:
                print("Elevation Failed")
            else:
                if response.level <= self.__level.value:
                    raise ResponseError(str(response), "Cannot have a level lower than or equal to mine")
                self.__level.value = response.level
                print(f"Elevation success. Current level: {self.level}")
            self.__action.elevating -= 1

        self.__action.elevating += 1
        self.__api.send(IncantationRequest(incantation_handler))

    @property
    def elevating(self) -> int:
        return self.__action.elevating

    def doing_an_action(self) -> bool:
        return self.__action.ongoing()

    @property
    def pos(self) -> Position:
        return self.__pos

    @property
    def inventory(self) -> Inventory:
        return self.__inventory

    @property
    def vision(self) -> Vision:
        return self.__vision

    @property
    def level(self) -> int:
        return self.__level.value

    @property
    def role(self) -> Role:
        return self.__role

    @role.setter
    def role(self, r: Role) -> None:
        if not isinstance(r, Role):
            raise TypeError("Must be a Role enum")
        self.__role = r

    def project_position(self, unit: int, divergence: int) -> Position:
        projection: Dict[Orientation, Position] = {
            Orientation.North: Position(self.pos.x + divergence, self.pos.y + unit),
            Orientation.South: Position(self.pos.x - divergence, self.pos.y - unit),
            Orientation.East: Position(self.pos.x + unit, self.pos.y - divergence),
            Orientation.West: Position(self.pos.x - unit, self.pos.y + divergence),
        }
        return projection[self.__orientation]

    def __handle_spontaneous_responses(self, spontaneous_responses: List[SpontaneousResponse]) -> None:
        handler_map: Dict[Type[SpontaneousResponse], Callable[[Any], None]] = {
            DeadResponse: lambda rp: self.__kill(),
            MessageResponse: self.__listen,
        }

        for rp in spontaneous_responses:
            handler: Optional[Callable[[SpontaneousResponse], None]] = handler_map.get(type(rp))
            if callable(handler):
                handler(rp)

    def __kill(self) -> NoReturn:
        raise PlayerDeadError()

    def __listen(self, message: MessageResponse) -> None:
        print(f"From tile {message.tile}: {repr(message.text)}")
        try:
            if callable(self.__message_listener):
                self.__message_listener(Message(message.tile, message.text))
        except MessageError:
            pass
