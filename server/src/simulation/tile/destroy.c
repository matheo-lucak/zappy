/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** destroy
*/

#include <stdlib.h>
#include "simulation/tile.h"

void destroy_tile(tile_t *tile)
{
    if (!tile)
        return;
    ptr_list_destroy(tile->players_on_tile);
    ptr_list_destroy(tile->objects_on_tile);
    free(tile);
}
