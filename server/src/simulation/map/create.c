/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** create
*/

#include <stdlib.h>
#include "simulation/map.h"

static void destroy_map_until(map_t *map,
                        unsigned int width, unsigned int height)
{
    map->width = width;
    map->height = height;
    destroy_map(map);
}

map_t *create_map(unsigned int width, unsigned int height)
{
    map_t *map = malloc(sizeof(map_t));

    if (!map)
        return NULL;
    map->width = width;
    map->height = height;
    map->tiles = malloc(sizeof(tile_t *) * height);
    if (!map->tiles) {
        destroy_map(map);
        return NULL;
    }
    for (unsigned int y = 0; y < height; y++) {
        map->tiles[y] = malloc(sizeof(tile_t) * width);
        if (!map->tiles[y]) {
            destroy_map_until(map, width, height);
            return NULL;
        }
        for (unsigned int x = 0; x < width; x++) {
            map->tiles[y][x] = create_tile(x, y);
            if (!map->tiles[y][x]) {
                destroy_map_until(map, y + 1, x + 1);
                return NULL;
            }
        }
    }
    return map;
}
