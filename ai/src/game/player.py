# -*- coding: Utf-8 -*

from typing import Dict, List

from .inventory import Inventory
from .vision import Vision
from ..api_server import APIServer
from ..api_server.request.broadcast import BroadcastRequest
from ..api_server.request.inventory import InventoryRequest, InventoryResponse
from ..api_server.request.forward import ForwardRequest
from ..api_server.request.look import LookRequest, LookResponse
from ..api_server.request.left import LeftRequest
from ..api_server.request.right import RightRequest
from ..api_server.request.set_object_down import SetObjectDownRequest, SetObjectDownResponse
from ..api_server.request.take_object import TakeObjectRequest, TakeObjectResponse
from ..api_server.request.response.spontaneous import MessageResponse
from ..errors import ZappyError


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
    def __init__(self, team_name: str, api: APIServer) -> None:
        self.__team: str = team_name
        self.__inventory: Inventory = Inventory()
        self.__vision: Vision = Vision()
        self.__api: APIServer = api
        self.__messages: List[Message] = list()

        self.__forwarding: int = 0
        self.__turning_left: int = 0
        self.__turning_right: int = 0

        self.__taking_resource: Dict[str, int] = dict()
        self.__setting_resource: Dict[str, int] = dict()

        self.__api.send(InventoryRequest(self.__inventory.update))
        self.__api.send(LookRequest(self.__vision.update))

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

    def listen(self, message: MessageResponse) -> None:
        print(f"From tile {message.tile}: {repr(message.text)}")
        self.__messages.append(Message(message.tile, message.text))

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

    @property
    def team(self) -> str:
        return self.__team

    @property
    def inventory(self) -> Inventory:
        return self.__inventory

    @property
    def vision(self) -> Vision:
        return self.__vision
