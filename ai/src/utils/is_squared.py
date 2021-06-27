# -*- coding: utf-8 -*

from math import isqrt
from functools import lru_cache


@lru_cache(maxsize=20)
def is_squared(nb: int) -> bool:
    return (isqrt(nb) ** 2) == nb
