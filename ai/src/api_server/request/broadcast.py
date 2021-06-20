# -*- coding: Utf-8 -*

from typing import Optional

from .base import BaseRequest, ResponseCallback
from .response import Response
from .response.exceptions import ResponseParsingError


class BroadcastResponse(Response):
    def __init__(self, response: str) -> None:
        super().__init__(response)
        if response != "ok":
            raise ResponseParsingError(response, "Should be 'ok'")

    @property
    def ok(self) -> bool:
        return True


class BroadcastRequest(BaseRequest[BroadcastResponse]):
    def __init__(self, text: str, callback: Optional[ResponseCallback[BroadcastResponse]] = None) -> None:
        super().__init__("Broadcast", text, callback=callback)
