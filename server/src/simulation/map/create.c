/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** create
*/

#include <stdlib.h>

#include "simulation/map.h"

static void map_compute_expected_resources(map_t *map)
{
    size_t tile_nb = map->width * map->height;
    const resource_info_t *info = NULL;

    for (size_t i = 0; i < resource_infos_size; i++) {
        info = &resource_infos[i];
        map->expected[info->type] = info->density * tile_nb;
    }
}

static void map_destroy_until(map_t *map,
                            unsigned int width,
                            unsigned int height)
{
    map->width = width;
    map->height = height;
    map_destroy(map);
}

static bool map_fill_with_tiles(map_t *map, unsigned int width, unsigned int height)
{
    for (unsigned int y = 0; y < height; y++) {
        map->tiles[y] = malloc(sizeof(tile_t) * width);
        if (!map->tiles[y]) {
            map_destroy_until(map, width, y);
            return false;
        }
        for (unsigned int x = 0; x < width; x++) {
            map->tiles[y][x] = tile_create();
            if (!map->tiles[y][x]) {
                map_destroy_until(map, x, y + 1);
                return false;
            }
        }
    }
    return true;
}

map_t *map_create(unsigned int width, unsigned int height)
{
    map_t *map = malloc(sizeof(map_t));

    if (!map)
        return NULL;
    map->width = width;
    map->height = height;
    map->tiles = malloc(sizeof(tile_t *) * height);
    map->time_until_refill = 0;
    if (!map->tiles) {
        map_destroy(map);
        return NULL;
    }
    if (!map_fill_with_tiles(map, width, height)) {
        map_destroy(map);
        return NULL;
    }
    map_compute_expected_resources(map);
    map_refill(map);
    return map;
}
