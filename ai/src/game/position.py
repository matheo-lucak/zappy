# -*- coding: Utf-8 -*

from typing import NamedTuple
from enum import IntEnum, auto, unique


class Position(NamedTuple):
    x: int
    y: int


@unique
class Orientation(IntEnum):
    North = auto()
    South = auto()
    East = auto()
    West = auto()
