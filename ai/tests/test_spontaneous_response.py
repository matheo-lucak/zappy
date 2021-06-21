# -*- coding: Utf-8 -*

import pytest
from re import Pattern
from typing import Optional
from src.api_server.request.response.exceptions import ResponseParsingError

from src.api_server.request.response.spontaneous import SpontaneousResponse, DeadResponse, MessageResponse


def test_spontaneous_response_class_instantiation() -> None:
    with pytest.raises(TypeError):
        rp: SpontaneousResponse = SpontaneousResponse("a")


def test_spontaneous_response_class_pattern() -> None:
    with pytest.raises(TypeError):
        pattern: Pattern[str] = SpontaneousResponse.get_pattern()


def test_spontaneous_response_find_dead_response() -> None:
    rp: Optional[SpontaneousResponse] = SpontaneousResponse.find("dead")
    assert isinstance(rp, DeadResponse)


def test_spontaneous_response_find_message_response() -> None:
    rp: Optional[SpontaneousResponse] = SpontaneousResponse.find("message 4, I'm here")
    assert isinstance(rp, MessageResponse)
    assert rp.tile == 4
    assert rp.text == "I'm here"


def test_spontaneous_response_no_match() -> None:
    rp: Optional[SpontaneousResponse] = SpontaneousResponse.find("[food 5, sibur 6]")
    assert rp is None


def test_dead_response() -> None:
    rp: DeadResponse = DeadResponse("dead")
    assert rp.match.group() == "dead"


def test_dead_response_invalid() -> None:
    with pytest.raises(ResponseParsingError):
        rp: DeadResponse = DeadResponse("nope")


def test_message_response() -> None:
    rp: MessageResponse = MessageResponse("message 4, Yo")
    assert rp.match.group(1) == "4"
    assert rp.match.group(2) == "Yo"
    assert rp.tile == 4
    assert rp.text == "Yo"


def test_message_response_whitespace_handling() -> None:
    rp: MessageResponse = MessageResponse("message 4   ,    Yo")
    assert rp.match.group(1) == "4"
    assert rp.match.group(2) == "Yo"
    assert rp.tile == 4
    assert rp.text == "Yo"


def test_message_response_whitespace_handling_2() -> None:
    rp: MessageResponse = MessageResponse("message 4,Yo")
    assert rp.match.group(1) == "4"
    assert rp.match.group(2) == "Yo"
    assert rp.tile == 4
    assert rp.text == "Yo"


def test_message_response_invalid() -> None:
    with pytest.raises(ResponseParsingError):
        rp: MessageResponse = MessageResponse("message a, Yo")

    with pytest.raises(ResponseParsingError):
        rp = MessageResponse("message, Yo")

    with pytest.raises(ResponseParsingError):
        rp = MessageResponse("message 5, ")

    with pytest.raises(ResponseParsingError):
        rp = MessageResponse("messge 4, Yo")

    with pytest.raises(ResponseParsingError):
        rp = MessageResponse("message4, Yo")
