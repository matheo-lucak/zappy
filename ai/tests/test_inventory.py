# -*- coding: Utf-8 -*

import pytest
from src.api_server.request.response.exceptions import ResponseError

from src.game.inventory import Inventory
from src.api_server.request.inventory import InventoryResponse


def test_inventory() -> None:
    inventory: Inventory = Inventory()
    assert inventory["food"] == 10
    assert inventory["linemate"] == 0
    assert inventory["deraumere"] == 0
    assert inventory["sibur"] == 0
    assert inventory["mendiane"] == 0
    assert inventory["phiras"] == 0
    assert inventory["thystame"] == 0

    assert "food" in inventory
    assert "linemate" not in inventory


def test_inventory_update_by_response() -> None:
    inventory: Inventory = Inventory()
    inventory.update(InventoryResponse("[food 60, linemate 5, deraumere 2, sibur 0, mendiane 4, phiras 1, thystame 3]"))
    assert inventory["food"] == 60
    assert inventory["linemate"] == 5
    assert inventory["deraumere"] == 2
    assert inventory["sibur"] == 0
    assert inventory["mendiane"] == 4
    assert inventory["phiras"] == 1
    assert inventory["thystame"] == 3


def test_inventory_update_by_response_invalid() -> None:
    inventory: Inventory = Inventory()
    rp: InventoryResponse

    rp = InventoryResponse("[food 60, deraumere 2, sibur 0, mendiane 4, phiras 1, thystame 3]")
    with pytest.raises(ResponseError):  # Missing resource
        inventory.update(rp)

    rp = InventoryResponse("[food 60, linemate 5, deraumere 2, hello 123, sibur 0, mendiane 4, phiras 1, thystame 3]")
    with pytest.raises(ResponseError):  # Unknown resource
        inventory.update(rp)

    assert inventory["food"] == 10
    assert inventory["linemate"] == 0
    assert inventory["deraumere"] == 0
    assert inventory["sibur"] == 0
    assert inventory["mendiane"] == 0
    assert inventory["phiras"] == 0
    assert inventory["thystame"] == 0
