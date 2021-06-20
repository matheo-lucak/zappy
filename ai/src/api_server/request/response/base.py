# -*- coding: Utf-8 -*

class Response:

    END_RESPONSE: str = "\n"

    def __init__(self, response: str) -> None:
        self.__response: str = response

    def __repr__(self) -> str:
        return f"<{type(self).__name__}({repr(self.__response)})>"

    def __str__(self) -> str:
        return self.__response
