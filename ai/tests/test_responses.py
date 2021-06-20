# -*- coding: Utf-8 -*

from src.api_server.request.response import Response


def test_response_creation() -> None:
    rp: Response = Response("a b c")
    assert str(rp) == "a b c"
