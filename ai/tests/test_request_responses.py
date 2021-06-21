# -*- coding: Utf-8 -*

import pytest

from src.api_server.request.inventory import InventoryResponse
from src.api_server.request.broadcast import BroadcastResponse
from src.api_server.request.look import LookResponse
from src.api_server.request.response.exceptions import ResponseParsingError


def test_inventory_response() -> None:
    rp: InventoryResponse = InventoryResponse("[food 345, sibur 3, phiras 5, deraumere 0]")
    assert rp.resources["food"] == 345
    assert rp.resources["sibur"] == 3
    assert rp.resources["phiras"] == 5
    assert rp.resources["deraumere"] == 0


def test_inventory_response_whitespace_handling() -> None:
    rp: InventoryResponse = InventoryResponse("[   food   345   ,   sibur  3, phiras 5    , deraumere 0    ]")
    assert rp.resources["food"] == 345
    assert rp.resources["sibur"] == 3
    assert rp.resources["phiras"] == 5
    assert rp.resources["deraumere"] == 0


def test_inventory_response_invalid() -> None:
    with pytest.raises(ResponseParsingError):
        rp: InventoryResponse = InventoryResponse("[food 34a, sibur 3, phiras 5, deraumere 0]")

    with pytest.raises(ResponseParsingError):
        rp = InventoryResponse("[fo0d 345, sibur 3, phiras 5, deraumere 0]")

    with pytest.raises(ResponseParsingError):
        rp = InventoryResponse("[food 345, sibur, phiras 5, deraumere 0]")

    with pytest.raises(ResponseParsingError):
        rp = InventoryResponse("food 345, sibur 3, phiras 5, deraumere 0")

    with pytest.raises(ResponseParsingError):
        rp = InventoryResponse("food 345, sibur 3, phiras 5, deraumere 0]")

    with pytest.raises(ResponseParsingError):
        rp = InventoryResponse("[food 345, sibur 3, phiras 5, deraumere 0")

    with pytest.raises(ResponseParsingError):
        rp = InventoryResponse("[food 345, [sibur 3, phiras 5], deraumere 0]")

    with pytest.raises(ResponseParsingError):
        rp = InventoryResponse("[food 345, (sibur 3, phiras 5), deraumere 0]")


def test_broadcast_response() -> None:
    rp: BroadcastResponse = BroadcastResponse("ok")
    assert rp.ok is True


def test_broadcast_response_invalid() -> None:
    with pytest.raises(ResponseParsingError):
        rp: BroadcastResponse = BroadcastResponse("ko")


def test_look_response() -> None:
    rp: LookResponse = LookResponse("[player, thystame, sibur phiras, deraumere deraumere]")
    assert len(rp.tiles) == 4
    assert rp.tiles[0]["player"] == 1
    assert rp.tiles[1]["thystame"] == 1
    assert rp.tiles[2]["sibur"] == 1
    assert rp.tiles[2]["phiras"] == 1
    assert rp.tiles[3]["deraumere"] == 2


def test_look_response_empty_slots() -> None:
    rp: LookResponse = LookResponse("[player, player deraumere, , ]")
    assert len(rp.tiles) == 4
    assert rp.tiles[0]["player"] == 1
    assert rp.tiles[1]["player"] == 1
    assert rp.tiles[1]["deraumere"] == 1
    assert len(rp.tiles[2]) == 0
    assert len(rp.tiles[3]) == 0


def test_look_response_invalid() -> None:
    with pytest.raises(ResponseParsingError):
        rp: LookResponse = LookResponse("[]")

    with pytest.raises(ResponseParsingError):
        rp = LookResponse("player, thystame, sibur phiras, deraumere deraumere")

    with pytest.raises(ResponseParsingError):
        rp = LookResponse("[player, [thystame, sibur phiras], deraumere deraumere]")

    with pytest.raises(ResponseParsingError):
        rp = LookResponse("[player, thystame, (sibur phiras), deraumere deraumere]")

    with pytest.raises(ResponseParsingError):
        rp = LookResponse("[player, thystame, sibur ph1ras, deraumere deraumere]")

    with pytest.raises(ResponseParsingError):
        rp = LookResponse("[player, thystame, sibur]")
