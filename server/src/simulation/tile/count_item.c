/*
** EPITECH PROJECT, 2021
** server
** File description:
** count_item
*/

#include "simulation/tile.h"

size_t tile_count_item(tile_t *tile, resource_type_t type)
{
    size_t count = 0;

    if (!tile)
        return false;
    list_foreach(node, tile->items) {
        if (NODE_DATA(node, resource_type_t) == type)
            count++;
    }
    return count;
}
