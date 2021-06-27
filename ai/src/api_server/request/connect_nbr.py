# -*- coding: utf-8 -*

from typing import Optional

from .base import BaseRequest, ResponseCallback
from .response import Response
from .response.exceptions import ResponseParsingError


class ConnectNbrResponse(Response):
    def __init__(self, response: str) -> None:
        super().__init__(response)
        if not response.isdigit():
            raise ResponseParsingError(response, "Not a positive integer")
        self.__value: int = int(response)

    @property
    def value(self) -> int:
        return self.__value


class ConnectNbrRequest(BaseRequest[ConnectNbrResponse], process_time=0):
    def __init__(self, callback: Optional[ResponseCallback[ConnectNbrResponse]] = None) -> None:
        super().__init__("Connect_nbr", callback=callback)
