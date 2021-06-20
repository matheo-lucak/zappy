# -*- coding: Utf-8 -*

from .base import Response
from .exceptions import ResponseParsingError

class WelcomeResponse(Response):

    def __init__(self, response: str) -> None:
        super().__init__(response)
        if response != "WELCOME":
            raise ResponseParsingError(f"{repr(response)} is not the WELCOME response")