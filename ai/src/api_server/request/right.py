# -*- coding: utf-8 -*

from typing import Optional

from .base import BaseRequest, ResponseCallback
from .response.ok import OKResponse


class RightResponse(OKResponse):
    pass


class RightRequest(BaseRequest[RightResponse], process_time=7):
    def __init__(self, callback: Optional[ResponseCallback[RightResponse]] = None) -> None:
        super().__init__("Right", callback=callback)
