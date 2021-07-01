# -*- coding: Utf-8 -*

from sys import stderr
from typing import List, NamedTuple, Optional
from multiprocessing import Process

from .api_server import APIServer
from .api_server.request import TeamRequest, ConnectNbrRequest
from .api_server.request.connect_nbr import ConnectNbrResponse
from .api_server.request.response import MapSizeAtBeginningResponse, WelcomeResponse
from .errors import ZappyError
from .game import Player, AI
from .game.player import EggLayingGenerator
from .log import Logger


class ZappyAIArgs(NamedTuple):
    machine: str
    port: int
    team_name: str
    verbose: int


class ZappyAI:
    def __init__(self, machine: str, port: int, team_name: str, child: bool) -> None:
        self.__child_processes: List[Process] = list()

        self.__machine: str = machine
        self.__port: int = port
        self.__server: APIServer = APIServer(machine, port)

        if self.__server.recv(WelcomeResponse) is None:
            raise ZappyError("No welcome message received from server")

        team: TeamRequest = TeamRequest(team_name)
        self.__server.send(team)
        while team.response is None:
            self.__server.fetch()
        if team.response.client_num is None:
            raise ZappyError(f"Cannot integrate team {repr(team_name)}")
        print(f"{team.response.client_num} player(s) left can be in team {repr(team_name)}")

        map_size: Optional[MapSizeAtBeginningResponse] = self.__server.recv(MapSizeAtBeginningResponse)
        if map_size is None:
            raise ZappyError("The server did not send the map size")
        print(f"Map size: {(map_size.width, map_size.height)}")

        self.__team: str = team_name
        self.__player: Player = Player(team_name, self.__server, self.__egg_laying_handler)
        self.__ai: AI = AI(self.__player, team_name, child)

    def __del__(self) -> None:
        for process in self.__child_processes:
            if process.is_alive():
                process.terminate()
        self.__child_processes.clear()

    def run(self) -> None:
        self.__ai.start()
        for process in self.__child_processes:
            while process.is_alive():
                continue
        self.__child_processes.clear()

    @staticmethod
    def start(machine: str, port: int, team_name: str, child: bool = False) -> None:
        try:
            ai: ZappyAI = ZappyAI(machine, port, team_name, child)
            ai.run()
        except (ConnectionError, BlockingIOError, ZappyError) as e:
            print(e, file=stderr)
        except EOFError:
            print("Remote server closes this connection. Disconnecting...", file=stderr)
        except KeyboardInterrupt:
            print("\n" "AI stopped by user. Disconnecting...", file=stderr)

    def __egg_laying_handler(self) -> EggLayingGenerator:
        egg_hatching_time_in_ticks: int = 600
        ticks_count: int = 0
        unused_slots: int = 0

        def connect_nbr_handler(response: ConnectNbrResponse) -> None:
            nonlocal ticks_count, unused_slots
            unused_slots = response.value
            ticks_count += response.ticks

        while ticks_count < egg_hatching_time_in_ticks + 10:
            if not self.__player.elevating and not self.__server.has_request_to_handle(ConnectNbrRequest):
                self.__server.send(ConnectNbrRequest(connect_nbr_handler))
            yield
        if unused_slots > 0:
            print("<---- An egg hatched ---->")
            p: Process = Process(target=ZappyAI.start, args=(self.__machine, self.__port, self.__team, True))
            p.start()


def zappy_ai(args: ZappyAIArgs) -> None:
    Logger.set_verbose_level(args.verbose)
    return ZappyAI.start(args.machine, args.port, args.team_name)
