/*
** EPITECH PROJECT, 2021
** server
** File description:
** refill
*/

#include <stdlib.h>

#include "simulation/map.h"

static void map_refill_one_tile(tile_t *tile, resource_type_t t,
                                resource_quantity_t *q_to_spawn,
                                bool spawn_on_different_spot)
{
    if (spawn_on_different_spot && tile_count_item(tile, t) == 0) {
        tile_add_item(tile, t);
        (*q_to_spawn) -= 1;
    } else if (!spawn_on_different_spot) {
        tile_add_item(tile, t);
        (*q_to_spawn) -= 1;
    }
}

static void map_refill_tiles_rec(map_t *map, resource_type_t t,
                                resource_quantity_t q_to_spawn,
                                bool spawn_on_different_spot)
{
    tile_t *tile = NULL;
    unsigned int i = 0;
    unsigned int y = rand() % map->height;

    if (q_to_spawn <= 0)
        return;
    for (; i < map->height; i++) {
        for (unsigned x = 0; x < map->width; x++) {
            tile = map->tiles[y][x];
            if (q_to_spawn <= 0)
                return;
            map_refill_one_tile(tile, t, &q_to_spawn, spawn_on_different_spot);
        }
        y += 1;
        if (y == map->height - 1)
            y = 0;
    }
    if (q_to_spawn > 0)
        map_refill_tiles_rec(map, t, q_to_spawn, false);
}

static void map_refill_tiles(map_t *map)
{
    resource_quantities_t count = {0};

    map_count_resources(map, &count);
    for (int i = 0; i < RESOURCE_NB; i++) {
        map_refill_tiles_rec(map, i, map->expected[i] - count[i], true);
    }
}

bool map_refill(map_t *map)
{
    if (map->time_until_refill > 0) {
        map->time_until_refill -= 1;
        return false;
    }
    map_refill_tiles(map);
    map->time_until_refill = MAP_TIME_TO_REFILL;
    return true;
}
