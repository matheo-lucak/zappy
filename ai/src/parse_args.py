# -*- coding: Utf-8 -*

from sys import argv
from argparse import ArgumentParser, Namespace, ArgumentTypeError
from typing import List
from .errors import Error, HelpError, Result
from .zappy_ai import ZappyAIArgs

def integer_between(argument: str, port_min: int, port_max: int) -> int:
    try:
        value: int = int(argument)
    except ValueError:
        raise ArgumentTypeError("Must be an integer") from None
    if not (port_min <= value <= port_max):
        raise ArgumentTypeError(f"Port value must be between {port_min} and {port_max}")
    return value

def parse_args(arguments: List[str] = argv[1:]) -> Result[ZappyAIArgs]:
    parser: ArgumentParser = ArgumentParser(prog="zappy_ai", add_help=False)
    parser.add_argument("-help", action="store_true", help="shows this help and exit")
    parser.add_argument("-p", type=lambda arg: integer_between(arg, 0, pow(2, 16) - 1), metavar="port", required=True, help="is the port number")
    parser.add_argument("-n", metavar="name", required=True, help="is the name of the team")
    parser.add_argument("-h", metavar="machine", default="localhost", help="is the name of the machine; localhost by default")
    try:
        if "-help" in arguments:
            parser.print_help()
            return HelpError("Help Error")
        args: Namespace = parser.parse_args(args=arguments)
    except SystemExit as exception:
        return Error(str(exception))
    if args.help:
        parser.print_help()
        return HelpError("Help Error")
    return ZappyAIArgs(machine=args.h, port=args.p, name=args.n)