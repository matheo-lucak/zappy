# -*- coding: Utf-8 -*

from typing import Dict, Optional

from .base import BaseRequest, ResponseCallback
from .response import Response
from .response.exceptions import ResponseParsingError


class InventoryResponse(Response):
    def __init__(self, response: str) -> None:
        super().__init__(response)
        self.__resources: Dict[str, int] = dict()

        if response[0] != "[" or response[-1] != "]":
            raise ResponseParsingError(response, "Should be between '[]' brackets")

        response = response[1:-1]
        if any(response.find(char) >= 0 for char in "[]()"):
            raise ResponseParsingError(response, "There are brackets inside the list")

        for resource in response.split(","):
            resource = resource.strip()
            try:
                name, amount = resource.split()
                if not name.isalpha():
                    raise ValueError
                if not amount.isdigit():
                    raise ValueError
                self.__resources[name] = int(amount)
            except ValueError:
                raise ResponseParsingError(response, "Invalid format") from None

    @property
    def resources(self) -> Dict[str, int]:
        return self.__resources


class InventoryRequest(BaseRequest[InventoryResponse], process_time=1):
    def __init__(self, callback: Optional[ResponseCallback[InventoryResponse]] = None) -> None:
        super().__init__("Inventory", callback=callback)
