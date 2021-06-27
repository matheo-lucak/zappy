# -*- coding: Utf-8 -*

from src.utils import is_squared


def test_is_squared() -> None:
    assert is_squared(0)
    assert is_squared(1)
    assert is_squared(4)
    assert is_squared(9)
    assert is_squared(16)

    assert not is_squared(2)
    assert not is_squared(3)
    assert not is_squared(5)
    assert not is_squared(6)
    assert not is_squared(7)
    assert not is_squared(123)
