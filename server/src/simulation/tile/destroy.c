/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** destroy
*/

#include <stdlib.h>
#include "simulation/tile.h"

void tile_destroy(tile_t *tile)
{
    if (!tile)
        return;
    ptr_list_destroy(tile->drones);
    generic_list_destroy(tile->items);
    free(tile);
}
