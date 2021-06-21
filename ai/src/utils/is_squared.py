# -*- coding: utf-8 -*

from math import isqrt


def is_squared(nb: int) -> bool:
    return (isqrt(nb) ** 2) == nb
