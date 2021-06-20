# -*- coding: Utf-8 -*

from .inventory import Inventory
from .vision import Vision
from ..api_server import APIServer
from ..api_server.request import InventoryRequest


class Player:
    def __init__(self, team_name: str) -> None:
        self.__team: str = team_name
        self.__inventory: Inventory = Inventory()
        self.__vision: Vision = Vision()
        self.__alive: bool = True

    def update(self, api: APIServer) -> None:
        api.send(InventoryRequest(self.__inventory.update))

    def is_alive(self) -> bool:
        return self.__alive

    def kill(self) -> None:
        self.__alive = False

    @property
    def team(self) -> str:
        return self.__team

    @property
    def inventory(self) -> Inventory:
        return self.__inventory

    @property
    def vision(self) -> Vision:
        return self.__vision
