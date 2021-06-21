# -*- coding: Utf-8 -*

from typing import Dict, List, Optional

from .base import BaseRequest, ResponseCallback
from .response import Response
from .response.exceptions import ResponseParsingError
from ...utils import is_squared


class LookResponse(Response):
    def __init__(self, response: str) -> None:
        super().__init__(response)
        self.__tiles: List[Dict[str, int]] = list()

        if response[0] != "[" or response[-1] != "]":
            raise ResponseParsingError(response, "Should be between '[]' brackets")

        response = response[1:-1]
        if not response:
            raise ResponseParsingError(response, "Invalid size")

        if any(response.find(char) >= 0 for char in "[]()"):
            raise ResponseParsingError(response, "There are brackets inside the list")

        for object_list in response.split(","):
            object_list = object_list.strip()
            tile: Dict[str, int] = dict()
            if object_list:
                for obj in object_list.split():
                    if not obj.isalpha():
                        raise ResponseParsingError(response, "Invalid format")
                    tile[obj] = tile.get(obj, 0) + 1
            self.__tiles.append(tile)

        if len(self.__tiles) == 0 or not is_squared(len(self.__tiles)):
            raise ResponseParsingError(response, "Invalid size")

    @property
    def tiles(self) -> List[Dict[str, int]]:
        return self.__tiles


class LookRequest(BaseRequest[LookResponse]):
    def __init__(self, callback: Optional[ResponseCallback[LookResponse]] = None) -> None:
        super().__init__("Look", callback=callback)
