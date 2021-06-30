# -*- coding: Utf-8 -*

import pytest

from src.game.message import Message, MessageError
from src.game.role import Role


def test_message_parsing() -> None:
    m: Message = Message(4, "12345678-1234-5678-1234-567812345678: my_team: lvl 5 (1): message")
    assert m.tile == 4
    assert str(m.uuid) == "12345678-1234-5678-1234-567812345678"
    assert m.team == "my_team"
    assert m.level == 5
    assert m.role == Role(1)
    assert m.body == "message"


def test_message_parsing_invalid() -> None:
    m: Message

    with pytest.raises(MessageError):
        m = Message(2, "Not a valid message")

    with pytest.raises(MessageError):
        m = Message(2, ": lvl 5 (1): message")

    with pytest.raises(MessageError):
        m = Message(2, "my_team: lvl (1): message")

    with pytest.raises(MessageError):
        m = Message(2, "my_team: lvl a(1): message")

    with pytest.raises(MessageError):
        m = Message(2, "my_team: lvl 2(1): ")
