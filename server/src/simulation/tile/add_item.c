/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** add_player
*/

#include <stdbool.h>
#include "simulation/tile.h"
#include "simulation/drone.h"

bool tile_add_item(tile_t *tile, resource_type_t type)
{
    int status = generic_list_push_back(tile->items, type, resource_type_t);

    return status == LIST_SUCCESS ? true : false;
}
