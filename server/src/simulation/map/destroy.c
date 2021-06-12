/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** destroy
*/

#include <stdlib.h>
#include "simulation/map.h"

static void destroy_tile_map(map_t *map)
{
    if (!map->tiles)
        return;
    for (unsigned int y = 0; y < map->height; y++) {
        for (unsigned int x = 0; x < map->width; x++) {
            destroy_tile(map->tiles[y][x]);
        }
    }
    free(map->tiles);
}

void destroy_map(map_t *map)
{
    if (!map)
        return;
    destroy_tile_map(map);
    free(map);
}
