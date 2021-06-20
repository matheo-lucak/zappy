# -*- coding: Utf-8 -*

from time import time_ns
from sys import stderr
from typing import Any, Callable, Dict, NamedTuple, Optional, Type

from .api_server import APIServer
from .api_server.request import TeamRequest
from .api_server.request.response import MapSizeAtBeginningResponse, WelcomeResponse
from .api_server.request.response.spontaneous import DeadResponse, MessageResponse, SpontaneousResponse
from .errors import ZappyError
from .game import Player
from .log import Logger


class ZappyAIArgs(NamedTuple):
    machine: str
    port: int
    team_name: str
    verbose: int


class Clock:
    def __init__(self) -> None:
        self.__actual: int = 0
        self.restart()

    def get_elapsed_time(self) -> int:
        return int((time_ns() - self.__actual) / (1000000))

    def elapsed_time(self, milliseconds: int, *, restart: bool = False) -> bool:
        if self.get_elapsed_time() < milliseconds:
            return False
        if restart:
            self.restart()
        return True

    def restart(self) -> None:
        self.__actual = time_ns()


class ZappyAI:
    def __init__(self, machine: str, port: int, team_name: str) -> None:
        self.__server: APIServer = APIServer(machine, port)

        if self.__server.recv(WelcomeResponse) is None:
            raise ZappyError("No welcome message received from server")

        team: TeamRequest = TeamRequest(team_name)
        self.__server.send(team)
        while team.response is None:
            self.__server.fetch()
        if team.response.client_num is None:
            raise ZappyError(f"Cannot integrate team {repr(team_name)}")
        print(f"{team.response.client_num} players left can be in team {repr(team_name)}")

        map_size: Optional[MapSizeAtBeginningResponse] = self.__server.recv(MapSizeAtBeginningResponse)
        if map_size is None:
            raise ZappyError("The server did not send the map size")
        print(f"Map size: {(map_size.width, map_size.height)}")

        self.__player: Player = Player(team_name, self.__server)
        print(self.__player.inventory)

    def run(self) -> None:
        clock: Clock = Clock()
        while self.__player.is_alive():
            self.__player.update()
            if clock.elapsed_time(1000, restart=True):
                self.__player.broadcast("I'm alive")
            self.__server.fetch()
            self.__handle_spontaneous_responses()

    def __handle_spontaneous_responses(self) -> None:
        handler_map: Dict[Type[SpontaneousResponse], Callable[[Any], None]] = {
            DeadResponse: lambda rp: self.__player.kill(),
            MessageResponse: self.__player.listen,
        }

        for rp in self.__server.flush_spontaneous_responses():
            handler: Optional[Callable[[SpontaneousResponse], None]] = handler_map.get(type(rp))
            if callable(handler):
                handler(rp)


def zappy_ai(args: ZappyAIArgs) -> None:
    try:
        Logger.set_verbose_level(args.verbose)
        ai: ZappyAI = ZappyAI(args.machine, args.port, args.team_name)
        ai.run()
    except (ConnectionError, BlockingIOError, ZappyError) as e:
        print(e, file=stderr)
    except EOFError:
        print("Remote server closes this connection. Disconnecting...", file=stderr)
    except KeyboardInterrupt:
        print("\n" "AI stopped by user. Disconnecting...", file=stderr)
