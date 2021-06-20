# -*- coding: Utf-8 -*

from typing import Optional

from .base import BaseRequest, ResponseCallback
from .response import Response

class BroadcastResponse(Response):
    pass

class BroadcastRequest(BaseRequest[BroadcastResponse]):

    def __init__(self, text: str, callback: Optional[ResponseCallback[BroadcastResponse]] = None) -> None:
        super().__init__("Broadcast", text, callback=callback)