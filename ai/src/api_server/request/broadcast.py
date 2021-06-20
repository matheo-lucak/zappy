# -*- coding: Utf-8 -*

from typing import Optional, Callable

from .base import BaseRequest, ResponseCallback
from .response.broadcast import BroadcastResponse

class BroadcastRequest(BaseRequest[BroadcastResponse]):
    
    def __init__(self, text: str, callback: Optional[ResponseCallback[BroadcastResponse]] = None) -> None:
        super().__init__("Broadcast", text, callback=callback)