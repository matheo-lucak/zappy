# -*- coding: Utf-8 -*

from enum import IntEnum, unique, auto


@unique
class Role(IntEnum):
    NewPlayer = auto()
    StoneSeeker = auto()
