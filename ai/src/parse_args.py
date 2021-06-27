# -*- coding: Utf-8 -*

from sys import argv
from argparse import ArgumentParser, ArgumentTypeError
from typing import List
from .errors import Error, Result
from .zappy_ai import ZappyAIArgs


class HelpError(Error):
    pass


class ArgumentParsingError(Error):
    pass


MAGIC_GUI_TEAM_NAME: str = "0xea83f3_gui_application"


def integer_between(argument: str, port_min: int, port_max: int) -> int:
    try:
        value: int = int(argument)
    except ValueError:
        raise ArgumentTypeError("Must be an integer") from None
    if not (port_min <= value < port_max):
        raise ArgumentTypeError(f"Port value must be in range [{port_min};{port_max}[")
    return value

def team_name(team: str) -> str:
    if team == MAGIC_GUI_TEAM_NAME:
        raise ArgumentTypeError(f"{repr(team)} team name is forbidden")
    return team


def parse_args(arguments: List[str] = argv[1:]) -> Result[ZappyAIArgs]:
    parser: ArgumentParser = ArgumentParser(prog="zappy_ai", conflict_handler="resolve")
    parser.add_argument(
        "-p",
        type=lambda arg: integer_between(arg, 0, pow(2, 16)),
        metavar="port",
        required=True,
        help="is the port number",
    )
    parser.add_argument("-n", metavar="name", type=team_name, required=True, help="is the name of the team")
    parser.add_argument("-h", metavar="machine", default="localhost", help="is the name of the machine; localhost by default")
    parser.add_argument("-v", action="count", default=0, help="Sets the verbose")
    try:
        args = parser.parse_args(args=arguments)
    except SystemExit as exception:
        if exception.code == 0:
            return HelpError("Help Error")
        return ArgumentParsingError("ArgumentParsingError")
    return ZappyAIArgs(machine=args.h, port=args.p, team_name=args.n, verbose=args.v)
