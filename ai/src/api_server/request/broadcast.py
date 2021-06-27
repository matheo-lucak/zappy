# -*- coding: Utf-8 -*

from typing import Optional

from .base import BaseRequest, ResponseCallback
from .response.ok import OKResponse


class BroadcastResponse(OKResponse):
    pass


class BroadcastRequest(BaseRequest[BroadcastResponse], process_time=7):
    def __init__(self, text: str, callback: Optional[ResponseCallback[BroadcastResponse]] = None) -> None:
        super().__init__("Broadcast", text, callback=callback)
