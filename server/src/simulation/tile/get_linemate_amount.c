/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** get_linemate_amount
*/

#include "simulation/tile.h"

unsigned int tile_get_linemate_amount(tile_t *tile)
{
    unsigned int count = 0;
    resource_type_t resource;

    list_foreach(node, tile->items) {
        resource = NODE_DATA(node, resource_type_t);
        if (resource == RESOURCE_LINEMATE)
            count += 1;
    }
    return count;
}
