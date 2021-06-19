# -*- coding: Utf-8 -*

from ....errors import ZappyError


class ResponseError(ZappyError):
    pass

class ResponseInitError(ResponseError):
    pass

class ResponseParsingError(ResponseError):
    pass