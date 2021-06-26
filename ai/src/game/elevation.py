# -*- coding: Utf-8 -*

from typing import Dict, NamedTuple, Tuple

from .resource import BaseResource, Linemate, Deraumere, Sibur, Mendiane, Phiras, Thystame


class Requirements(NamedTuple):
    nb_players: int
    resources: Tuple[BaseResource, ...]


Secrets = Dict[int, Requirements]


class Elevation:
    @staticmethod
    def get_requirements(level: int) -> Requirements:
        return Elevation.__SECRETS[level]

    @staticmethod
    def max_level() -> int:
        return max(Elevation.__SECRETS.keys()) + 1

    __SECRETS: Secrets = {
        1: Requirements(nb_players=1, resources=(Linemate(1),)),
        2: Requirements(nb_players=2, resources=(Linemate(1), Deraumere(1), Sibur(1))),
        3: Requirements(nb_players=2, resources=(Linemate(2), Sibur(1), Phiras(2))),
        4: Requirements(nb_players=4, resources=(Linemate(1), Deraumere(1), Sibur(2), Phiras(1))),
        5: Requirements(nb_players=4, resources=(Linemate(1), Deraumere(2), Sibur(1), Mendiane(3))),
        6: Requirements(nb_players=6, resources=(Linemate(1), Deraumere(2), Sibur(3), Phiras(1))),
        7: Requirements(nb_players=6, resources=(Linemate(2), Deraumere(2), Sibur(2), Mendiane(2), Phiras(2), Thystame(1))),
    }
