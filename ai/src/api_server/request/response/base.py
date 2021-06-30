# -*- coding: Utf-8 -*


class Response:

    END_RESPONSE: str = "\n"

    def __init__(self, response: str) -> None:
        self.__response: str = response
        self.__ticks: int = 0

    def __repr__(self) -> str:
        return f"<{type(self).__name__}({repr(self.__response)})>"

    def __str__(self) -> str:
        return self.__response

    @property
    def ticks(self) -> int:
        return self.__ticks

    @ticks.setter
    def ticks(self, value: int) -> None:
        self.__ticks = max(int(value), 0)
