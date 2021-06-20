# -*- coding: Utf-8 -*

from typing import Dict

from .resource import MetaResource, BaseResource
from ..api_server.request.inventory import InventoryResponse
from ..api_server.request.response.exceptions import ResponseError


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
        return (
            f"Inventory: [{', '.join(f'{resource.name}: {resource.amount}' for resource in self.__resources.values())}]"
        )

    def __getitem__(self, resource: str) -> int:
        return self.__resources[resource].amount

    def update(self, response: InventoryResponse) -> None:
        if any(resource not in self.__resources for resource in response.resources):
            raise ResponseError(str(response), "Unknown resource caught")
        if any(resource not in response.resources for resource in self.__resources):
            raise ResponseError(str(response), "Missing a resource in the list")
        for name, amount in response.resources.items():
            self.__resources[name].amount = amount
        print("Inventory updated")
