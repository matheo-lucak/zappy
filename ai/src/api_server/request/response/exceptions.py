# -*- coding: Utf-8 -*

from ....errors import ZappyError


class ResponseError(ZappyError):
    pass

class ResponseParsingError(ResponseError):
    pass