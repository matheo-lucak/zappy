# -*- coding: Utf-8 -*

from .inventory import Inventory
from .vision import Vision
from ..api_server import APIServer
from ..api_server.request import BroadcastRequest, InventoryRequest
from ..api_server.request.response.spontaneous import MessageResponse
from ..log import Logger

class Player:
    def __init__(self, team_name: str, api: APIServer) -> None:
        self.__team: str = team_name
        self.__inventory: Inventory = Inventory()
        self.__vision: Vision = Vision()
        self.__alive: bool = True
        self.__api: APIServer = api

    def update(self) -> None:
        if not self.__api.has_request_to_handle(InventoryRequest):
            self.__api.send(InventoryRequest(self.__inventory.update))

    def is_alive(self) -> bool:
        return self.__alive

    def kill(self) -> None:
        if self.__alive:
            print("I'm dying...!")
            self.__alive = False

    def listen(self, message: MessageResponse) -> None:
        print(f"From tile {message.tile}: {repr(message.text)}")

    def broadcast(self, message: str) -> None:
        Logger.print(1, f"Broadcasting: {repr(message)}")
        self.__api.send(BroadcastRequest(message))

    @property
    def team(self) -> str:
        return self.__team

    @property
    def inventory(self) -> Inventory:
        return self.__inventory

    @property
    def vision(self) -> Vision:
        return self.__vision
