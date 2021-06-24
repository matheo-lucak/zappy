# -*- coding: Utf-8 -*

from typing import NamedTuple, Optional

from .api_server import APIServer
from .api_server.request import TeamRequest, LookRequest, InventoryRequest
from .api_server.request.inventory import InventoryResponse
from .api_server.request.response import MapSizeAtBeginningResponse, WelcomeResponse
from .errors import ZappyError
from .game import Player, AI, Algorithm, Framerate
from .log import Logger


class ZappyAIArgs(NamedTuple):
    machine: str
    port: int
    team_name: str
    verbose: int


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

        self.__ai: AI = AI(self.__player, Framerate(self.__server.get_framerate))

    def run(self) -> None:
        def first_inventory_update(response: InventoryResponse) -> None:
            self.__player.inventory.update(response)
            print(self.__player.inventory)

        inventory_request: InventoryRequest = InventoryRequest(first_inventory_update)
        look_request: LookRequest = LookRequest(self.__player.vision.update)
        self.__server.send(inventory_request)
        self.__server.send(look_request)
        while inventory_request.response is None and look_request.response is None:
            self.__server.fetch()
        print("AI setup finished.")

        algo: Algorithm = self.__ai.start()

        while True:
            if not self.__server.has_request_to_handle(LookRequest):
                self.__server.send(LookRequest(self.__player.vision.update))
            self.__server.fetch()
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


def zappy_ai(args: ZappyAIArgs) -> None:
    Logger.set_verbose_level(args.verbose)
    return ZappyAI.start(args.machine, args.port, args.team_name)
