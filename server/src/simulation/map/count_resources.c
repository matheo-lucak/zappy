/*
** EPITECH PROJECT, 2021
** server
** File description:
** count_resources
*/

#include "simulation/map.h"

static void map_count_resources_on_tile(tile_t *tile,
                        resource_quantities_t *count)
{
    for (int i = 0; i < RESOURCE_NB; i++) {
        (*count)[i] += tile_count_item(tile, i);
    }
}

void map_count_resources(map_t *map, resource_quantities_t *count)
{
    tile_t *tile = NULL;

    for (size_t y = 0; y < map->height; y++) {
        for (size_t x = 0; x < map->width; x++) {
            tile = map->tiles[y][x];
            map_count_resources_on_tile(tile, count);
        }
    }
}
