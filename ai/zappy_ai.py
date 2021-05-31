# -*- coding: Utf-8 -*

from sys import stderr
from typing import NamedTuple
from .api_server import APIServer

class ZappyAIArgs(NamedTuple):
    machine: str
    port: int
    name: str

class ZappyAI:

    def __init__(self, machine: str, port: int, name: str) -> None:
        self.__server: APIServer = APIServer(machine, port)
        self.__name = name

    def run(self) -> None:
        pass

def zappy_ai(args: ZappyAIArgs) -> None:
    try:
        ai: ZappyAI = ZappyAI(args.machine, args.port, args.name)
        ai.run()
    except Exception as e:
        print(e, file=stderr)