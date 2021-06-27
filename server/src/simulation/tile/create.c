/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** create
*/

#include <stdlib.h>
#include "simulation/tile.h"

tile_t *tile_create(void)
{
    tile_t *tile = calloc(1, sizeof(tile_t));

    if (!tile)
        return NULL;
    tile->drones = ptr_list_create(NULL);
    if (!tile->drones) {
        tile_destroy(tile);
        return NULL;
    }
    tile->items = generic_list_create(NULL);
    if (!tile->items) {
        tile_destroy(tile);
        return NULL;
    }
    return tile;
}
