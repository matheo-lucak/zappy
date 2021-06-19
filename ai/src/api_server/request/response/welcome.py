# -*- coding: Utf-8 -*

from .response import Response
from .exceptions import ResponseParsingError

class WelcomeResponse(Response):

    def parse(self, response: str) -> None:
        if response != "WELCOME":
            raise ResponseParsingError(f"{repr(response)} is not the WELCOME response")