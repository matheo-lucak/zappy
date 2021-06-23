# -*- coding: Utf-8 -*

from src.api_server.request import (
    BroadcastRequest,
    InventoryRequest,
    ForwardRequest,
    LeftRequest,
    LookRequest,
    RightRequest,
    Request,
    SetObjectDownRequest,
    TakeObjectRequest,
    TeamRequest,
)


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


def test_forward_request() -> None:
    req: ForwardRequest = ForwardRequest()
    assert req.command == "Forward"
    assert req.args == tuple()
    assert str(req) == "Forward"


def test_left_request() -> None:
    req: LeftRequest = LeftRequest()
    assert req.command == "Left"
    assert req.args == tuple()
    assert str(req) == "Left"


def test_look_request() -> None:
    req: LookRequest = LookRequest()
    assert req.command == "Look"
    assert req.args == tuple()
    assert str(req) == "Look"


def test_right_request() -> None:
    req: RightRequest = RightRequest()
    assert req.command == "Right"
    assert req.args == tuple()
    assert str(req) == "Right"


def test_set_object_down_request() -> None:
    req: SetObjectDownRequest = SetObjectDownRequest("linemate")
    assert req.command == "Set"
    assert req.args == ("linemate",)
    assert str(req) == "Set linemate"


def test_take_object_request() -> None:
    req: TakeObjectRequest = TakeObjectRequest("food")
    assert req.command == "Take"
    assert req.args == ("food",)
    assert str(req) == "Take food"
