# -*- coding: Utf-8 -*

from .base import MetaResource, BaseResource

__all__ = ["MetaResource", "BaseResource", "Food", "Linemate", "Deraumere", "Sibur", "Mendiane", "Phiras", "Thystame"]


class Food(BaseResource, resource="food", density=0.5):
    pass


class Linemate(BaseResource, resource="linemate", density=0.3):
    pass


class Deraumere(BaseResource, resource="deraumere", density=0.15):
    pass


class Sibur(BaseResource, resource="sibur", density=0.1):
    pass


class Mendiane(BaseResource, resource="mendiane", density=0.1):
    pass


class Phiras(BaseResource, resource="phiras", density=0.08):
    pass


class Thystame(BaseResource, resource="thystame", density=0.05):
    pass
