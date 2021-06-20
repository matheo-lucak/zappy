# -*- coding: Utf-8 -*

from src.api_server.request import BroadcastRequest, InventoryRequest, Request, TeamRequest


def test_request_class_creation() -> None:
    req: Request = Request("bct", "X", "Y")
    assert req.command == "bct"
    assert req.args == ("X", "Y")
    assert str(req) == "bct X Y"


def test_team_request_creation() -> None:
    req: TeamRequest = TeamRequest("my_team")
    assert req.command == "my_team"
    assert req.args == tuple()
    assert str(req) == "my_team"


def test_inventory_request() -> None:
    req: InventoryRequest = InventoryRequest()
    assert req.command == "Inventory"
    assert req.args == tuple()
    assert str(req) == "Inventory"


def test_broadcast_request() -> None:
    req: BroadcastRequest = BroadcastRequest("I'm alive")
    assert req.command == "Broadcast"
    assert req.args == ("I'm alive",)
    assert str(req) == "Broadcast I'm alive"
