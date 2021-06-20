# -*- coding: Utf-8 -*

from typing import Dict

from .resource import MetaResource, BaseResource


class Inventory:

    __SETUP: Dict[str, int] = {
        "food": 10,
    }

    def __init__(self) -> None:
        self.__resources: Dict[str, BaseResource] = dict()
        for resource in MetaResource.get_all_resources():
            self.__resources[resource] = MetaResource.create(resource, self.__SETUP.get(resource, 0))

    def __repr__(self) -> str:
        return f"<{type(self).__name__}{tuple(self.__resources.values())}>"

    def __str__(self) -> str:
        return f"Inventory: [{', '.join(f'{resource.name}: {resource.amount}' for resource in self.__resources.values())}]"

    def __getitem__(self, resource: str) -> int:
        return self.__resources[resource].amount
