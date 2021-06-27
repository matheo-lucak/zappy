/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** destroy
*/

#include <stdlib.h>
#include "simulation/map.h"

static void map_destroy_tile(map_t *map)
{
    if (!map->tiles)
        return;
    for (unsigned int y = 0; y < map->height; y++) {
        for (unsigned int x = 0; x < map->width; x++) {
            tile_destroy(map->tiles[y][x]);
        }
        free(map->tiles[y]);
    }
    free(map->tiles);
}

void map_destroy(map_t *map)
{
    if (!map)
        return;
    map_destroy_tile(map);
    free(map);
}
