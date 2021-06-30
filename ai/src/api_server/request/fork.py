# -*- coding: utf-8 -*

from typing import Optional

from .base import BaseRequest, ResponseCallback
from .response.ok import OKResponse


class ForkResponse(OKResponse):
    pass


class ForkRequest(BaseRequest[ForkResponse], process_time=7):
    def __init__(self, callback: Optional[ResponseCallback[ForkResponse]] = None) -> None:
        super().__init__("Fork", callback=callback)
