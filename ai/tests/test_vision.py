# -*- coding :utf-8 -*

from typing import List
from src.game.vision import Coords, Vision
from src.api_server.request.look import LookResponse


def test_vision() -> None:
    vision: Vision = Vision()
    assert vision.max_unit == 1
    assert len(vision.tiles) == 4
    assert all(
        len(tile.resources) == 0 and tile.nb_players == 0 and tile.index == index for index, tile in enumerate(vision.tiles)
    )
    assert vision.get(0, 0) == vision.tiles[0]
    assert vision.get(1, -1) == vision.tiles[1]
    assert vision.get(1, 0) == vision.tiles[2]
    assert vision.get(1, 1) == vision.tiles[3]

    assert vision.get(0, 0).unit == 0
    assert vision.get(0, 0).divergence == 0

    assert vision.get(1, -1).unit == 1
    assert vision.get(1, -1).divergence == -1

    assert vision.get(1, 0).unit == 1
    assert vision.get(1, 0).divergence == 0

    assert vision.get(1, 1).unit == 1
    assert vision.get(1, 1).divergence == 1


def test_vision_update_by_response() -> None:
    vision: Vision = Vision()
    vision.update(LookResponse("[player linemate, thystame, sibur phiras linemate, deraumere deraumere]"))

    assert len(vision.get(0, 0).resources) == 1
    assert len(vision.get(1, -1).resources) == 1
    assert len(vision.get(1, 0).resources) == 3
    assert len(vision.get(1, 1).resources) == 1

    assert vision.get(0, 0).nb_players == 1
    assert vision.get(1, -1).nb_players == 0
    assert vision.get(1, 0).nb_players == 0
    assert vision.get(1, 1).nb_players == 0

    assert "linemate" in vision.get(0, 0)
    assert vision.get(0, 0)["linemate"] == 1

    assert "thystame" in vision.get(1, -1)
    assert vision.get(1, -1)["thystame"] == 1

    assert "sibur" in vision.get(1, 0)
    assert vision.get(1, 0)["sibur"] == 1
    assert "phiras" in vision.get(1, 0)
    assert vision.get(1, 0)["phiras"] == 1
    assert "linemate" in vision.get(0, 0)
    assert vision.get(1, 0)["linemate"] == 1

    assert "deraumere" in vision.get(1, 1)
    assert vision.get(1, 1)["deraumere"] == 2

    assert "linemate" in vision
    assert "food" not in vision

def test_vision_find() -> None:
    vision: Vision = Vision()
    vision.update(LookResponse("[player linemate, thystame, sibur phiras linemate, deraumere deraumere]"))

    assert "linemate" in vision
    assert "food" not in vision

    linemates: List[Coords] = vision.find("linemate")
    assert len(linemates) == 2
    assert linemates[0] == (0, 0)
    assert linemates[1] == (1, 0)
    assert len(vision.find("food")) == 0