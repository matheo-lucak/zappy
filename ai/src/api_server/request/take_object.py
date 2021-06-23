# -*- coding: Utf-8 -*

from typing import Optional

from .base import BaseRequest, ResponseCallback
from .response.ok import OKorKOResponse


class TakeObjectResponse(OKorKOResponse):
    pass


class TakeObjectRequest(BaseRequest[TakeObjectResponse]):
    def __init__(self, resource: str, callback: Optional[ResponseCallback[TakeObjectResponse]] = None) -> None:
        super().__init__("Take", resource, callback=callback)
