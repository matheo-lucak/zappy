# -*- coding: Utf-8  -*

from uuid import UUID
from re import compile as regex_compile, Match, Pattern
from typing import Optional

from .role import Role
from ..errors import ZappyError


class MessageError(ZappyError):
    pass


class MessageTileError(MessageError):
    def __init__(self, tile: int) -> None:
        super().__init__(f"{tile}: Must be in range [0;8]")


class MessageBodyError(MessageError):
    def __init__(self, message: str) -> None:
        super().__init__(f"{repr(message)}: Invalid format")


UUID_PATTERN: str = r"[0-9a-fA-F]{8}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{12}"


class Message:

    PATTERN: Pattern[str] = regex_compile(rf"({UUID_PATTERN}): +(\w+): +lvl +([0-9]+) *\(([0-9]+)\): +([^\s][^\n]*)")

    def __init__(self, tile: int, text: str) -> None:
        self.__tile: int = tile

        if self.__tile not in range(9):
            raise MessageTileError(self.__tile)

        match: Optional[Match[str]] = self.PATTERN.match(text)
        if match is None:
            raise MessageBodyError(text)

        self.__uuid: UUID = UUID(hex=match.group(1))
        self.__team: str = match.group(2)
        self.__level: int = int(match.group(3))
        self.__role: Role = Role(int(match.group(4)))
        self.__body: str = match.group(5)

    @property
    def tile(self) -> int:
        return self.__tile

    @property
    def uuid(self) -> UUID:
        return self.__uuid

    @property
    def team(self) -> str:
        return self.__team

    @property
    def level(self) -> int:
        return self.__level

    @property
    def role(self) -> Role:
        return self.__role

    @property
    def body(self) -> str:
        return self.__body
