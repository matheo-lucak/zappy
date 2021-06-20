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


def integer_between(argument: str, port_min: int, port_max: int) -> int:
    try:
        value: int = int(argument)
    except ValueError:
        raise ArgumentTypeError("Must be an integer") from None
    if not (port_min <= value < port_max):
        raise ArgumentTypeError(f"Port value must be in range [{port_min};{port_max}[")
    return value


def parse_args(arguments: List[str] = argv[1:]) -> Result[ZappyAIArgs]:
    parser: ArgumentParser = ArgumentParser(prog="zappy_ai", conflict_handler="resolve")
    parser.add_argument(
        "-p",
        type=lambda arg: integer_between(arg, 0, pow(2, 16)),
        metavar="port",
        required=True,
        help="is the port number",
    )
    parser.add_argument("-n", metavar="name", required=True, help="is the name of the team")
    parser.add_argument("-h", metavar="machine", default="localhost", help="is the name of the machine; localhost by default")
    try:
        args = parser.parse_args(args=arguments)
    except SystemExit as exception:
        if exception.code == 0:
            return HelpError("Help Error")
        return ArgumentParsingError("ArgumentParsingError")
    return ZappyAIArgs(machine=args.h, port=args.p, team_name=args.n)
