# -*- coding: utf-8 -*

from typing import Optional

from .base import BaseRequest, ResponseCallback
from .response.ok import OKResponse


class ForwardResponse(OKResponse):
    pass


class ForwardRequest(BaseRequest[ForwardResponse], process_time=7):
    def __init__(self, callback: Optional[ResponseCallback[ForwardResponse]] = None) -> None:
        super().__init__("Forward", callback=callback)
