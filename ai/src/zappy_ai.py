# -*- coding: Utf-8 -*

from sys import stderr
from typing import NamedTuple, Optional

from .api_server import APIServer
from .api_server.request import TeamRequest
from .api_server.request.response import MapSizeAtBeginningResponse, WelcomeResponse
from .errors import ZappyError
from .game import Player

class ZappyAIArgs(NamedTuple):
    machine: str
    port: int
    team_name: str

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

        self.__player: Player = Player(team_name)

    def run(self) -> None:
        pass

def zappy_ai(args: ZappyAIArgs) -> None:
    try:
        ai: ZappyAI = ZappyAI(args.machine, args.port, args.team_name)
        ai.run()
    except (ConnectionError, BlockingIOError, ZappyError) as e:
        print(e, file=stderr)
    except EOFError:
        print("Remote server closes this connection. Disconnecting...", file=stderr)
    except KeyboardInterrupt:
        print("AI stopped by user. Disconnecting...", file=stderr)