# -*- coding: Utf-8 -*

from ....errors import ZappyError


class ResponseError(ZappyError):

    def __init__(self, response: str, message: str) -> None:
        super().__init__(f"{repr(response)}: {message}")

class ResponseParsingError(ResponseError):
    pass
