/*
** EPITECH PROJECT, 2021
** server
** File description:
** remove_item
*/

#include <stdbool.h>
#include "simulation/tile.h"

bool tile_remove_item(tile_t *tile, resource_type_t type)
{
    return generic_list_remove(tile->items, type, resource_type_t)
        == LIST_SUCCESS;
}
