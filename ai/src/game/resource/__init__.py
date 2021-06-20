# -*- coding: Utf-8 -*

from .base import MetaResource, BaseResource

__all__ = ["MetaResource", "BaseResource", "Food", "Linemate", "Deraumere", "Sibur", "Mendiane", "Phiras", "Thystame"]


class Food(BaseResource, resource="food"):
    pass


class Linemate(BaseResource, resource="linemate"):
    pass


class Deraumere(BaseResource, resource="deraumere"):
    pass


class Sibur(BaseResource, resource="sibur"):
    pass


class Mendiane(BaseResource, resource="mendiane"):
    pass


class Phiras(BaseResource, resource="phiras"):
    pass


class Thystame(BaseResource, resource="thystame"):
    pass
