# -*- coding: Utf-8 -*

from typing import Dict, Tuple

Coords = Tuple[int, int]
Grid = Dict[Coords, "Tile"]

class Tile:

    def __init__(self, unit: int, divergence: int, index: int) -> None:
        self.__unit: int = unit
        self.__divergence: int = divergence
        self.__index: int = index

    @property
    def unit(self) -> int:
        return self.__unit

    @property
    def divergence(self) -> int:
        return self.__divergence

    @property
    def index(self) -> int:
        return self.__index

class Vision:

    DEFAULT_UNIT: int = 1

    def __init__(self) -> None:
        self.__grid: Grid = dict()
        self.unit = self.DEFAULT_UNIT

    def get(self, unit: int, divergence: int) -> Tile:
        return self.__grid[unit, divergence]

    @property
    def unit(self) -> int:
        return self.__vision_unit

    @unit.setter
    def unit(self, value: int) -> None:
        self.__vision_unit = max(int(value), 0)
        save: Grid = self.__grid
        self.__grid = dict()

        index: int = 0
        for unit in range(self.__vision_unit + 1):
            for divergence in range(-unit, unit + 1):
                self.__grid[unit, divergence] = Tile(unit, divergence, index)
                index += 1