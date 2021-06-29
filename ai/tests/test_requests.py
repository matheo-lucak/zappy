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
    assert req.get_process_time() == 0


def test_team_request_creation() -> None:
    req: TeamRequest = TeamRequest("my_team")
    assert req.command == "my_team"
    assert req.args == tuple()
    assert str(req) == "my_team"
    assert req.get_process_time() == 0


def test_inventory_request() -> None:
    req: InventoryRequest = InventoryRequest()
    assert req.command == "Inventory"
    assert req.args == tuple()
    assert str(req) == "Inventory"
    assert req.get_process_time() == 1


def test_broadcast_request() -> None:
    req: BroadcastRequest = BroadcastRequest("I'm alive")
    assert req.command == "Broadcast"
    assert req.args == ("I'm alive",)
    assert str(req) == "Broadcast I'm alive"
    assert req.get_process_time() == 7


def test_forward_request() -> None:
    req: ForwardRequest = ForwardRequest()
    assert req.command == "Forward"
    assert req.args == tuple()
    assert str(req) == "Forward"
    assert req.get_process_time() == 7


def test_left_request() -> None:
    req: LeftRequest = LeftRequest()
    assert req.command == "Left"
    assert req.args == tuple()
    assert str(req) == "Left"
    assert req.get_process_time() == 7


def test_look_request() -> None:
    req: LookRequest = LookRequest()
    assert req.command == "Look"
    assert req.args == tuple()
    assert str(req) == "Look"
    assert req.get_process_time() == 7


def test_right_request() -> None:
    req: RightRequest = RightRequest()
    assert req.command == "Right"
    assert req.args == tuple()
    assert str(req) == "Right"
    assert req.get_process_time() == 7


def test_set_object_down_request() -> None:
    req: SetObjectDownRequest = SetObjectDownRequest("linemate")
    assert req.command == "Set"
    assert req.args == ("linemate",)
    assert str(req) == "Set linemate"
    assert req.get_process_time() == 7


def test_take_object_request() -> None:
    req: TakeObjectRequest = TakeObjectRequest("food")
    assert req.command == "Take"
    assert req.args == ("food",)
    assert str(req) == "Take food"
    assert req.get_process_time() == 7
