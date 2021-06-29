# -*- coding: utf-8 -*

from typing import Optional

from .base import BaseRequest, ResponseCallback
from .response.ok import OKResponse


class LeftResponse(OKResponse):
    pass


class LeftRequest(BaseRequest[LeftResponse], process_time=7):
    def __init__(self, callback: Optional[ResponseCallback[LeftResponse]] = None) -> None:
        super().__init__("Left", callback=callback)
