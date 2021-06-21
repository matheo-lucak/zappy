# -*- coding: Utf-8 -*

from typing import List

from .inventory import Inventory
from .vision import Vision
from ..api_server import APIServer
from ..api_server.request import BroadcastRequest, InventoryRequest, LookRequest
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

    @property
    def team(self) -> str:
        return self.__team

    @property
    def inventory(self) -> Inventory:
        return self.__inventory

    @property
    def vision(self) -> Vision:
        return self.__vision
