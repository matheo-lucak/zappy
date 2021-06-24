# -*- coding: Utf-8 -*

import pytest

from src.api_server.request.response import Response
from src.api_server.request.response.welcome import WelcomeResponse
from src.api_server.request.response.map_size import MapSizeAtBeginningResponse
from src.api_server.request.team import TeamResponse
from src.api_server.request.response.exceptions import ResponseParsingError


def test_response_creation() -> None:
    rp: Response = Response("a b c")
    assert str(rp) == "a b c"


def test_welcome_response() -> None:
    rp: WelcomeResponse = WelcomeResponse("WELCOME")
    assert str(rp) == "WELCOME"


def test_welcome_response_invalid() -> None:
    with pytest.raises(ResponseParsingError):
        rp: WelcomeResponse = WelcomeResponse("welcome")


def test_team_response() -> None:
    rp: TeamResponse = TeamResponse("5")
    assert str(rp) == "5"
    assert rp.client_num is not None
    assert rp.client_num == 5


def test_team_response_ko() -> None:
    rp: TeamResponse = TeamResponse("ko")
    assert str(rp) == "ko"
    assert rp.client_num is None


def test_team_response_invalid() -> None:
    with pytest.raises(ResponseParsingError):
        rp: TeamResponse = TeamResponse("something_else")


def test_map_size_response() -> None:
    rp: MapSizeAtBeginningResponse = MapSizeAtBeginningResponse("15 30")
    assert str(rp) == "15 30"
    assert rp.width == 15
    assert rp.height == 30


def test_map_size_response_invalid() -> None:
    with pytest.raises(ResponseParsingError):
        rp: MapSizeAtBeginningResponse = MapSizeAtBeginningResponse("2a 5")

    with pytest.raises(ResponseParsingError):
        rp = MapSizeAtBeginningResponse("30")
