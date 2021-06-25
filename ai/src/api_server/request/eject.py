# -*- coding: Utf-8 -*

from typing import Optional

from .base import BaseRequest, ResponseCallback
from .response.ok import OKorKOResponse


class EjectResponse(OKorKOResponse):
    pass


class EjectRequest(BaseRequest[EjectResponse], process_time=7):
    def __init__(self, callback: Optional[ResponseCallback[EjectResponse]] = None) -> None:
        super().__init__("Eject", callback=callback)
