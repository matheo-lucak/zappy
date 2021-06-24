# -*- coding: Utf-8 -*

from typing import Dict, Iterator, List, Tuple
from math import isqrt

from ..api_server.request.look import LookResponse
from ..api_server.request.response.exceptions import ResponseError
from .resource import BaseResource, MetaResource
from .resource.exception import ResourceError


class Tile:
    def __init__(self, unit: int, divergence: int, index: int, content: Dict[str, int] = {}) -> None:
        self.__unit: int = unit
        self.__divergence: int = divergence
        self.__index: int = index
        self.__players: int = 0
        resources: List[BaseResource] = list()
        for obj, amount in content.items():
            if obj == "player":
                self.__players += amount
            else:
                resources.append(MetaResource.create(obj, amount))
        self.__resources: Tuple[BaseResource, ...] = tuple(resources)

    def __repr__(self) -> str:
        return f"{type(self).__name__}(resources={self.__resources}, nb_players={self.__players})"

    def __getitem__(self, resource: str) -> int:
        for r in self.__resources:
            if r.name == resource:
                return r.amount
        raise KeyError(resource)

    def __contains__(self, resource: str) -> bool:
        if resource == "player":
            return self.nb_players > 0
        return any(r.name == resource for r in self.__resources)

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
    def resources(self) -> Tuple[BaseResource, ...]:
        return self.__resources

    @property
    def nb_players(self) -> int:
        return self.__players


Coords = Tuple[int, int]
Grid = Dict[Coords, Tile]


class Vision:

    DEFAULT_UNIT: int = 1

    def __init__(self) -> None:
        self.__grid: Grid = dict()
        self.__vision_unit: int = 0

    def get(self, unit: int, divergence: int) -> Tile:
        return self.__grid[unit, divergence]

    def __contains__(self, resource: str) -> bool:
        return any(resource in tile for tile in self.__grid.values())

    @property
    def max_unit(self) -> int:
        return self.__vision_unit

    @property
    def tiles(self) -> Tuple[Tile, ...]:
        return tuple(self.__grid.values())

    def update(self, response: LookResponse) -> None:
        new_grid: Grid = dict()
        vision_unit: int = isqrt(len(response.tiles)) - 1

        if vision_unit <= 0:
            raise ResponseError(str(response), "I don't see anything")
        for index, (unit, divergence) in enumerate(self.iter_units(vision_unit)):
            try:
                new_grid[unit, divergence] = Tile(unit, divergence, index, response.tiles[index])
            except ResourceError as e:
                raise ResponseError(str(response), str(e))
        if new_grid[0, 0].nb_players < 1:
            raise ResponseError(str(response), "I'm a ghost, so what ?")

        self.__vision_unit = vision_unit
        self.__grid = new_grid

    @staticmethod
    def iter_units(max_unit: int) -> Iterator[Coords]:
        for unit in range(max_unit + 1):
            for divergence in range(-unit, unit + 1):
                yield (unit, divergence)

    def find(self, resource: str) -> List[Coords]:
        coords_list: List[Coords] = list()
        for coord, tile in self.__grid.items():
            if resource in tile:
                coords_list.append(coord)
        return coords_list
