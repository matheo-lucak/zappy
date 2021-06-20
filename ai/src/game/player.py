# -*- coding: Utf-8 -*

from ..api_server import APIServer
from .inventory import Inventory
from .vision import Vision

class Player:

    def __init__(self, team_name: str) -> None:
        self.__team: str = team_name
        self.__inventory: Inventory = Inventory()
        self.__vision: Vision = Vision()

    def update(self, api: APIServer) -> None:
        pass

    @property
    def team(self) -> str:
        return self.__team

    @property
    def inventory(self) -> Inventory:
        return self.__inventory

    @property
    def vision(self) -> Vision:
        return self.__vision
