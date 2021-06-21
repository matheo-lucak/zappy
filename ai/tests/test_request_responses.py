# -*- coding: Utf-8 -*

import pytest

from src.api_server.request.inventory import InventoryResponse
from src.api_server.request.broadcast import BroadcastResponse
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
