# -*- coding: Utf-8 -*

from typing import Dict, Iterator, Tuple, Union

from .resource import MetaResource, BaseResource
from ..api_server.request.inventory import InventoryResponse
from ..api_server.request.response.exceptions import ResponseError


InventoryView = Iterator[Tuple[str, int]]


class Inventory:
    def __init__(self) -> None:
        self.__resources: Dict[str, BaseResource] = dict()
        for resource in MetaResource.get_all_resources():
            self.__resources[resource] = MetaResource.create(resource)

    def __repr__(self) -> str:
        return f"<{type(self).__name__}{tuple(self.__resources.values())}>"

    def __str__(self) -> str:
        return f"Inventory: [{', '.join(f'{resource.name}: {resource.amount}' for resource in self.__resources.values())}]"

    def get(self, resource: Union[str, BaseResource]) -> int:
        if isinstance(resource, BaseResource):
            return self.__resources[resource.name].amount
        return self.__resources[resource].amount

    def __getitem__(self, resource: Union[str, BaseResource]) -> int:
        return self.get(resource)

    def __contains__(self, resource: Union[str, BaseResource]) -> bool:
        return self.get(resource) > 0

    def __iter__(self) -> InventoryView:
        for resource in self.__resources.values():
            yield (resource.name, resource.amount)

    def update(self, response: InventoryResponse) -> None:
        if any(resource not in self.__resources for resource in response.resources):
            raise ResponseError(str(response), "Unknown resource caught")
        if any(resource not in response.resources for resource in self.__resources):
            raise ResponseError(str(response), "Missing a resource in the list")
        for name, amount in response.resources.items():
            self.__resources[name].amount = amount
