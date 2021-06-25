# -*- coding: Utf-8 -*

from typing import Any, Callable, Dict, List, Optional, Type, NoReturn

from .inventory import Inventory
from .vision import Vision
from ..api_server import APIServer
from ..api_server.request.broadcast import BroadcastRequest
from ..api_server.request.eject import EjectRequest, EjectResponse
from ..api_server.request.forward import ForwardRequest
from ..api_server.request.inventory import InventoryRequest, InventoryResponse
from ..api_server.request.look import LookRequest, LookResponse
from ..api_server.request.left import LeftRequest
from ..api_server.request.right import RightRequest
from ..api_server.request.set_object_down import SetObjectDownRequest, SetObjectDownResponse
from ..api_server.request.take_object import TakeObjectRequest, TakeObjectResponse
from ..api_server.request.response.spontaneous import SpontaneousResponse, DeadResponse, MessageResponse
from ..errors import ZappyError


class PlayerDeadError(ZappyError):
    def __init__(self) -> None:
        super().__init__("I'm dying...!")


class Message:
    def __init__(self, tile: int, text: str) -> None:
        self.__tile: int = tile
        self.__text: str = text

    @property
    def tile(self) -> int:
        return self.__tile

    @property
    def text(self) -> str:
        return self.__text


class Player:
    def __init__(self, api: APIServer) -> None:
        self.__inventory: Inventory = Inventory()
        self.__vision: Vision = Vision()
        self.__api: APIServer = api
        self.__messages: List[Message] = list()

        self.__forwarding: int = 0
        self.__turning_left: int = 0
        self.__turning_right: int = 0
        self.__ejecting: int = 0

        self.__taking_resource: Dict[str, int] = dict()
        self.__setting_resource: Dict[str, int] = dict()

        self.__api.set_spontaneous_response_handler(self.__handle_spontaneous_responses)

    def move_forward(self, nb_times: int = 1) -> None:
        def forward_handler() -> None:
            print("Forward: Waiting for vision update...")

        def look_handler(response: LookResponse) -> None:
            self.__vision.update(response)
            print("Vision up-to-date")
            print("Move forward action completed")
            self.__forwarding -= 1

        for _ in range(nb_times):
            print("Moving forward...")
            self.__forwarding += 1
            self.__api.send(ForwardRequest(lambda rp: forward_handler()))
            self.__api.send(LookRequest(look_handler))

    @property
    def moving_forward(self) -> int:
        return self.__forwarding

    def turn_left(self, nb_times: int = 1) -> None:
        def turn_handler() -> None:
            print("Turn left: Waiting for vision update...")

        def look_handler(response: LookResponse) -> None:
            self.__vision.update(response)
            print("Vision up-to-date")
            print("Left rotation completed")
            self.__turning_left -= 1

        for _ in range(nb_times):
            print("Turning 90deg left...")
            self.__turning_left += 1
            self.__api.send(LeftRequest(lambda rp: turn_handler()))
            self.__api.send(LookRequest(look_handler))

    @property
    def turning_left(self) -> int:
        return self.__turning_left

    def turn_right(self, nb_times: int = 1) -> None:
        def turn_handler() -> None:
            print("Turn right: Waiting for vision update...")

        def look_handler(response: LookResponse) -> None:
            self.__vision.update(response)
            print("Vision up-to-date")
            print("Right rotation completed")
            self.__turning_right -= 1

        for _ in range(nb_times):
            print("Turning 90deg right...")
            self.__turning_right += 1
            self.__api.send(RightRequest(lambda rp: turn_handler()))
            self.__api.send(LookRequest(look_handler))

    @property
    def turning_right(self) -> int:
        return self.__turning_right

    def broadcast(self, message: str) -> None:
        print(f"Broadcasting: {repr(message)}")
        self.__api.send(BroadcastRequest(message))

    def flush_messages(self) -> List[Message]:
        messages: List[Message] = self.__messages
        self.__messages = list()
        return messages

    def take_object(self, resource: str) -> None:
        def take_handler(response: TakeObjectResponse) -> None:
            print(f"{repr(resource)}: {'taken' if response.ok else 'not taken'}")
            print("Waiting for vision and inventory update...")

        def look_handler(response: LookResponse) -> None:
            self.__vision.update(response)
            print("Vision up-to-date")

        def inventory_handler(response: InventoryResponse) -> None:
            self.__inventory.update(response)
            print("Inventory up-to-date")
            print("->", self.__inventory)
            self.__taking_resource[resource] = self.taking_object(resource) - 1
            if self.__taking_resource[resource] < 1:
                self.__taking_resource.pop(resource)

        print(f"Taking {resource}...")
        self.__taking_resource[resource] = self.taking_object(resource) + 1
        self.__api.send(TakeObjectRequest(resource, callback=take_handler))
        self.__api.send(LookRequest(look_handler))
        self.__api.send(InventoryRequest(inventory_handler))

    def taking_object(self, resource: str) -> int:
        return self.__taking_resource.get(resource, 0)

    def set_object_down(self, resource: str) -> None:
        def take_handler(response: SetObjectDownResponse) -> None:
            print(f"{repr(resource)}: {'set down' if response.ok else 'not set down'}")
            print("Waiting for vision and inventory update...")

        def look_handler(response: LookResponse) -> None:
            self.__vision.update(response)
            print("Vision up-to-date")

        def inventory_handler(response: InventoryResponse) -> None:
            self.__inventory.update(response)
            print("Inventory up-to-date")
            print("->", self.__inventory)
            self.__setting_resource[resource] = self.setting_object_down(resource) - 1
            if self.__setting_resource[resource] < 1:
                self.__setting_resource.pop(resource)

        print(f"Setting {resource} down...")
        self.__setting_resource[resource] = self.setting_object_down(resource) + 1
        self.__api.send(SetObjectDownRequest(resource, callback=take_handler))
        self.__api.send(LookRequest(look_handler))
        self.__api.send(InventoryRequest(inventory_handler))

    def setting_object_down(self, resource: str) -> int:
        return self.__setting_resource.get(resource, 0)

    def eject_from_this_tile(self) -> None:
        def eject_handler(response: EjectResponse) -> None:
            print(f"Ejected: {response.ok}. Waiting for vision update...")

        def look_handler(response: LookResponse) -> None:
            self.__vision.update(response)
            print("Vision up-to-date")
            self.__ejecting -= 1

        self.__ejecting += 1
        self.__api.send(EjectRequest(eject_handler))
        self.__api.send(LookRequest(look_handler))

    @property
    def ejecting_player(self) -> int:
        return self.__ejecting

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
        self.__messages.append(Message(message.tile, message.text))

    @property
    def inventory(self) -> Inventory:
        return self.__inventory

    @property
    def vision(self) -> Vision:
        return self.__vision
