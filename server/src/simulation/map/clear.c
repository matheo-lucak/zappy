/*
** EPITECH PROJECT, 2021
** server
** File description:
** clear
*/

#include "simulation/map.h"

void map_clear_resources(map_t *map)
{
    tile_t *tile = NULL;

    for (size_t y = 0; y < map->height; y++) {
        for (size_t x = 0; x < map->width; x++) {
            tile = map->tiles[y][x];
            tile_clear_items(tile);
        }
    }
}
