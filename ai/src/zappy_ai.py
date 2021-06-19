# -*- coding: Utf-8 -*

from sys import stderr
from typing import NamedTuple, Optional

from .api_server import APIServer
from .api_server.request import TeamRequest
from .api_server.request.response import MapSizeAtBeginningResponse, TeamResponse, WelcomeResponse
from .errors import ZappyError

class ZappyAIArgs(NamedTuple):
    machine: str
    port: int
    team_name: str

class ZappyAI:

    def __init__(self, machine: str, port: int, team_name: str) -> None:
        self.__server: APIServer = APIServer(machine, port)
        self.__team_name: str = team_name

        if self.__server.recv(WelcomeResponse) is None:
            raise ZappyError("No welcome message received from server")

        team_response: TeamResponse = self.__server.send_and_wait_for_response(TeamRequest(self.__team_name))
        if team_response.client_num is None:
            raise ZappyError(f"Cannot integrate team {repr(self.__team_name)}")
        print(team_response.client_num)

        map_size: Optional[MapSizeAtBeginningResponse] = self.__server.recv(MapSizeAtBeginningResponse)
        if map_size is None:
            raise ZappyError("The server did not send the map size")
        print((map_size.width, map_size.height))

    def run(self) -> None:
        pass

def zappy_ai(args: ZappyAIArgs) -> None:
    try:
        ai: ZappyAI = ZappyAI(args.machine, args.port, args.team_name)
        ai.run()
    except (ConnectionError, BlockingIOError, ZappyError) as e:
        print(e, file=stderr)
    except KeyboardInterrupt:
        print("AI stopped by user. Disconnecting...", file=stderr)