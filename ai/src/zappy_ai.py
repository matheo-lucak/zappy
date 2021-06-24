# -*- coding: Utf-8 -*

from typing import Any, Callable, Dict, NamedTuple, Optional, Type

from .api_server import APIServer
from .api_server.request import TeamRequest, LookRequest
from .api_server.request.response import MapSizeAtBeginningResponse, WelcomeResponse
from .api_server.request.response.spontaneous import DeadResponse, MessageResponse, SpontaneousResponse
from .errors import ZappyError
from .game import Player, AI, Algorithm
from .log import Logger


class ZappyAIArgs(NamedTuple):
    machine: str
    port: int
    team_name: str
    verbose: int


class PlayerDeadError(ZappyError):
    def __init__(self) -> None:
        super().__init__("I'm dying...!")


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
        print(f"{team.response.client_num} player(s) left can be in team {repr(team_name)}")

        map_size: Optional[MapSizeAtBeginningResponse] = self.__server.recv(MapSizeAtBeginningResponse)
        if map_size is None:
            raise ZappyError("The server did not send the map size")
        print(f"Map size: {(map_size.width, map_size.height)}")

        self.__player: Player = Player(team_name, self.__server)
        print(self.__player.inventory)

        self.__ai: AI = AI(self.__player)

    def run(self) -> None:
        algo: Algorithm = self.__ai.start()
        while True:
            if not self.__server.has_request_to_handle(LookRequest):
                self.__server.send(LookRequest(self.__player.vision.update))
            self.__server.fetch()
            self.__handle_spontaneous_responses()
            try:
                next(algo)
            except StopIteration:
                break

    @staticmethod
    def start(machine: str, port: int, team_name: str) -> None:
        try:
            ai: ZappyAI = ZappyAI(machine, port, team_name)
            ai.run()
        except (ConnectionError, BlockingIOError, ZappyError) as e:
            print(e)
        except EOFError:
            print("Remote server closes this connection. Disconnecting...")
        except KeyboardInterrupt:
            print("\n" "AI stopped by user. Disconnecting...")

    def __handle_spontaneous_responses(self) -> None:
        handler_map: Dict[Type[SpontaneousResponse], Callable[[Any], None]] = {
            MessageResponse: self.__player.listen,
        }

        for rp in self.__server.flush_spontaneous_responses():
            if isinstance(rp, DeadResponse):
                raise PlayerDeadError()
            handler: Optional[Callable[[SpontaneousResponse], None]] = handler_map.get(type(rp))
            if callable(handler):
                handler(rp)


def zappy_ai(args: ZappyAIArgs) -> None:
    Logger.set_verbose_level(args.verbose)
    return ZappyAI.start(args.machine, args.port, args.team_name)
