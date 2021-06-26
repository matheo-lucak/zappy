/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** add_player
*/

#include <stdbool.h>
#include "simulation/tile.h"
#include "simulation/drone.h"

bool tile_remove_item(tile_t *tile, resource_type_t type)
{
    int index = 0;
    bool found = false;

    if (!tile->items)
        return false;
    list_foreach(node, tile->items) {
        if (*NODE_PTR(node, resource_type_t) == type) {
            found = true;
            break;
        }
        index += 1;
    }
    if (!found)
        return false;
    list_pop(tile->items, index);
    return true;
}
