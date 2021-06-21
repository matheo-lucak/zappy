# -*- coding: Utf-8 -*

from .base import Response
from .exceptions import ResponseParsingError


class OKResponse(Response):
    def __init__(self, response: str) -> None:
        super().__init__(response)
        if response != "ok":
            raise ResponseParsingError(response, "Should be 'ok'")

    @property
    def ok(self) -> bool:
        return True


class OKorKOResponse(Response):
    def __init__(self, response: str) -> None:
        super().__init__(response)
        if response not in ("ok", "ko"):
            raise ResponseParsingError(response, "Should be 'ok'")
        self.__ok = response == "ok"

    @property
    def ok(self) -> bool:
        return self.__ok
