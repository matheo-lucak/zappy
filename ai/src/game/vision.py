# -*- coding: Utf-8 -*

from typing import Dict, Iterator, List, Tuple
from math import isqrt

from ..api_server.request.look import LookResponse
from .resource import BaseResource, MetaResource
from ..log import Logger


class Tile:
    def __init__(self, unit: int, divergence: int, index: int, content: Dict[str, int] = {}) -> None:
        self.__unit: int = unit
        self.__divergence: int = divergence
        self.__index: int = index
        self.__content: List[BaseResource] = list()
        self.__players: int = 0
        for obj, amount in content.items():
            if obj == "player":
                self.__players += amount
            else:
                self.__content.append(MetaResource.create(obj, amount))

    def __repr__(self) -> str:
        return f"{type(self).__name__}(resources={self.__content}, nb_players={self.__players})"

    @property
    def unit(self) -> int:
        return self.__unit

    @property
    def divergence(self) -> int:
        return self.__divergence

    @property
    def index(self) -> int:
        return self.__index

    @property
    def content(self) -> List[BaseResource]:
        return self.__content

    @property
    def nb_players(self) -> int:
        return self.__players


Coords = Tuple[int, int]
Grid = Dict[Coords, Tile]


class Vision:

    DEFAULT_UNIT: int = 1

    def __init__(self) -> None:
        self.__grid: Grid = dict()
        self.__vision_unit: int = self.DEFAULT_UNIT
        for index, (unit, divergence) in enumerate(self.iter_units(self.__vision_unit)):
            self.__grid[unit, divergence] = Tile(unit, divergence, index)

    def get(self, unit: int, divergence: int) -> Tile:
        return self.__grid[unit, divergence]

    @property
    def max_unit(self) -> int:
        return self.__vision_unit

    def update(self, response: LookResponse) -> None:
        self.__vision_unit = isqrt(len(response.tiles)) - 1
        self.__grid.clear()

        for index, (unit, divergence) in enumerate(self.iter_units(self.__vision_unit)):
            self.__grid[unit, divergence] = Tile(unit, divergence, index, response.tiles[index])

    @staticmethod
    def iter_units(max_unit: int) -> Iterator[Tuple[int, int]]:
        for unit in range(max_unit + 1):
            for divergence in range(-unit, unit + 1):
                yield (unit, divergence)
