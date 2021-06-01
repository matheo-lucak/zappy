# -*- coding: Utf-8 -*

from .base import ZappyRequest
from .response import ZappyResponse

class BroadcastResponse(ZappyResponse):

    def __init__(self, response: str) -> None:
        super().__init__()

class BroadcastRequest(ZappyRequest):

    def make_response(self, response: str) -> BroadcastResponse:
        return BroadcastResponse(response)