/*
** EPITECH PROJECT, 2021
** server
** File description:
** add_drone
*/

#include "simulation/drone.h"
#include "simulation/map.h"

bool map_add_drone(map_t *map, drone_t *drone)
{
    tile_t *tile = map->tiles[drone->pos.y][drone->pos.x];

    return tile_add_drone(tile, drone);
}