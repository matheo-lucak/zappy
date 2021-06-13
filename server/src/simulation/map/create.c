/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** create
*/

#include <stdlib.h>
#include "simulation/map.h"

static void map_destroy_until(map_t *map,
                            unsigned int width,
                            unsigned int height)
{
    map->width = width;
    map->height = height;
    map_destroy(map);
}

map_t *map_create(unsigned int width, unsigned int height)
{
    map_t *map = malloc(sizeof(map_t));

    if (!map)
        return NULL;
    map->width = width;
    map->height = height;
    map->tiles = malloc(sizeof(tile_t *) * height);
    if (!map->tiles) {
        map_destroy(map);
        return NULL;
    }
    for (unsigned int y = 0; y < height; y++) {
        map->tiles[y] = malloc(sizeof(tile_t) * width);
        if (!map->tiles[y]) {
            map_destroy_until(map, width, height);
            return NULL;
        }
        for (unsigned int x = 0; x < width; x++) {
            map->tiles[y][x] = tile_create(x, y);
            if (!map->tiles[y][x]) {
                map_destroy_until(map, y + 1, x + 1);
                return NULL;
            }
        }
    }
    return map;
}
