/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** create
*/

#include <stddef.h>
#include "simulation/tile.h"

tile_t *create_tile(unsigned int pos_x, unsigned int pos_y)
{
    tile_t *tile = malloc(sizeof(tile_t));

    if (!tile)
        return NULL;
    *tile = (tile_t){0};
    tile->pos_x = pos_x;
    tile->pos_y = pos_y;
    tile->players_on_tile = ptr_list_create(NULL);
    if (!tile->players_on_tile) {
        destroy_tile(tile);
        return NULL;
    }
    tile->objects_on_tile = ptr_list_create(NULL);
    if (!tile->objects_on_tile) {
        destroy_tile(tile);
        return NULL;
    }
    return tile;
}
