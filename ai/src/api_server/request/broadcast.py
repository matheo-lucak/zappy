# -*- coding: Utf-8 -*

from .base import BaseRequest
from .response.broadcast import BroadcastResponse

class BroadcastRequest(BaseRequest[BroadcastResponse], response=BroadcastResponse):
    pass