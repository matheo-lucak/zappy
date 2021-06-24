# -*- coding: Utf-8 -*

from io import StringIO
from src.log import Logger


def test_logger_no_verbose() -> None:
    buffer: StringIO = StringIO()
    Logger.set_verbose_level(0)
    assert Logger.get_verbose_level() == 0
    Logger.print(1, "First", file=buffer)
    Logger.print(2, "Second", file=buffer)
    Logger.print(0, "Third", file=buffer)
    assert buffer.getvalue() == "Third\n"


def test_logger_set_verbose() -> None:
    buffer: StringIO = StringIO()
    Logger.set_verbose_level(2)
    assert Logger.get_verbose_level() == 2
    Logger.print(1, "First", file=buffer)
    Logger.print(2, "Second", file=buffer)
    Logger.print(0, "Third", file=buffer)
    assert buffer.getvalue() == "First\nSecond\nThird\n"
