# -*- coding: Utf-8 -*

from typing import Optional

from .base import BaseRequest, ResponseCallback
from .response.ok import OKorKOResponse


class SetObjectDownResponse(OKorKOResponse):
    pass


class SetObjectDownRequest(BaseRequest[SetObjectDownResponse], process_time=7):
    def __init__(self, resource: str, callback: Optional[ResponseCallback[SetObjectDownResponse]] = None) -> None:
        super().__init__("Set", resource, callback=callback)
