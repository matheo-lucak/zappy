# -*- coding: Utf-8 -*

from src.api_server.request import Request


def test_request_class_creation() -> None:
    req: Request = Request("bct", "X", "Y")
    assert str(req) == "bct X Y\n"
