# -*- coding: Utf-8 -*

from typing import Any, Callable, List
from functools import wraps

from .inventory import Inventory
from .vision import Vision
from ..api_server import APIServer
from ..api_server.request.broadcast import BroadcastRequest
from ..api_server.request.inventory import InventoryRequest
from ..api_server.request.forward import ForwardRequest
from ..api_server.request.look import LookRequest
from ..api_server.request.left import LeftRequest
from ..api_server.request.right import RightRequest
from ..api_server.request.response.spontaneous import MessageResponse


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
        self.__alive: bool = True
        self.__api: APIServer = api
        self.__messages: List[Message] = list()

        self.__forwarding: int = 0
        self.__turning_left: int = 0
        self.__turning_right: int = 0

    def update(self) -> None:
        if not self.__api.has_request_to_handle(InventoryRequest):
            self.__api.send(InventoryRequest(self.__inventory.update))
        if not self.__api.has_request_to_handle(LookRequest):
            self.__api.send(LookRequest(self.__vision.update))

    def is_alive(self) -> bool:
        return self.__alive

    def kill(self) -> None:
        if self.__alive:
            print("I'm dying...!")
            self.__alive = False

    def move_forward(self, nb_times: int = 1) -> None:
        if not self.is_alive():
            return

        def handler() -> None:
            self.__forwarding -= 1
            print("Move forward completed")

        for _ in range(nb_times):
            print("Moving forward...")
            self.__forwarding += 1
            self.__api.send(ForwardRequest(lambda rp: handler()))

    @property
    def moving_forward(self) -> int:
        return self.__forwarding

    def turn_left(self, nb_times: int = 1) -> None:
        if not self.is_alive():
            return

        def handler() -> None:
            self.__turning_left -= 1
            print("Left rotation completed")

        for _ in range(nb_times):
            print("Turning 90deg left...")
            self.__turning_left += 1
            self.__api.send(LeftRequest(lambda rp: handler()))

    @property
    def turning_left(self) -> int:
        return self.__turning_left

    def turn_right(self, nb_times: int = 1) -> None:
        if not self.is_alive():
            return

        def handler() -> None:
            self.__turning_right -= 1
            print("Right rotation completed")

        for _ in range(nb_times):
            print("Turning 90deg right...")
            self.__turning_right += 1
            self.__api.send(RightRequest(lambda rp: handler()))

    @property
    def turning_right(self) -> int:
        return self.__turning_right

    def listen(self, message: MessageResponse) -> None:
        print(f"From tile {message.tile}: {repr(message.text)}")
        self.__messages.append(Message(message.tile, message.text))

    def broadcast(self, message: str) -> None:
        if not self.is_alive():
            return

        print(f"Broadcasting: {repr(message)}")
        self.__api.send(BroadcastRequest(message))

    def flush_messages(self) -> List[Message]:
        messages: List[Message] = self.__messages
        self.__messages = list()
        return messages

    @property
    def team(self) -> str:
        return self.__team

    @property
    def inventory(self) -> Inventory:
        return self.__inventory

    @property
    def vision(self) -> Vision:
        return self.__vision
