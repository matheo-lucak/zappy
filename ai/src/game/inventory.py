# -*- coding: Utf-8 -*

from typing import Dict


class Resource:

    def __init__(self, default_amount: int) -> None:
        self.amount = default_amount

    def __repr__(self) -> str:
        return f"<{type(self).__name__}({self.__amount})>"

    @property
    def amount(self) -> int:
        return self.__amount

    @amount.setter
    def amount(self, value: int) -> None:
        self.__amount = max(int(value), 0)

class Inventory:

    __SETUP: Dict[str, int] = {
        "food":      1260,
        "linemate":  0,
        "deraumere": 0,
        "sibur":     0,
        "mendiane":  0,
        "phiras":    0,
        "thystame":  0,
    }

    def __init__(self) -> None:
        self.__resources: Dict[str, Resource] = dict()
        for name, amount in self.__SETUP.items():
            self.__resources[name] = Resource(amount)

    def __repr__(self) -> str:
        return f"<{type(self).__name__}({self.__resources})>"

    @property
    def food(self) -> int:
        return self.__resources["food"].amount

    @property
    def linemate(self) -> int:
        return self.__resources["linemate"].amount

    @property
    def deraumere(self) -> int:
        return self.__resources["deraumere"].amount

    @property
    def sibur(self) -> int:
        return self.__resources["sibur"].amount

    @property
    def mendiane(self) -> int:
        return self.__resources["mendiane"].amount

    @property
    def phiras(self) -> int:
        return self.__resources["phiras"].amount

    @property
    def thystame(self) -> int:
        return self.__resources["thystame"].amount
