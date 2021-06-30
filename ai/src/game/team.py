# -*- coding: Utf-8 -*

from ..api_server import APIServer
from ..api_server.request.connect_nbr import ConnectNbrRequest, ConnectNbrResponse


class Team:
    def __init__(self, name: str, default_unused_slots: int, api: APIServer) -> None:
        self.__name: str = name
        self.__unused_slots: int = default_unused_slots
        self.__members: int = 1
        self.__api: APIServer = api

    def __ask_unused_slots(self) -> None:
        self.__api.send(ConnectNbrRequest(self.update))

    def update(self, response: ConnectNbrResponse) -> None:
        self.__unused_slots = response.value

    def start_asking_unused_slots(self) -> None:
        self.__api.add_fetch_callback(self.__ask_unused_slots)

    def stop_asking_unused_slots(self) -> None:
        self.__api.remove_fetch_callback(self.__ask_unused_slots)

    @property
    def name(self) -> str:
        return self.__name

    @property
    def unused_slots(self) -> int:
        return self.__unused_slots

    @property
    def members(self) -> int:
        return self.__members

    @members.setter
    def members(self, value: int) -> None:
        self.__members = max(int(value), 1)
