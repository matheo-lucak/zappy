/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** add_player
*/

#include <stdbool.h>
#include "simulation/tile.h"
#include "simulation/drone.h"

bool tile_remove_drone(tile_t *tile, drone_t *drone)
{
    int index = 0;
    bool found = false;

    if (!tile->drones)
        return false;
    list_foreach(node, tile->drones) {
        if (NODE_PTR(node, void *) == (void *)drone) {
            found = true;
            break;
        }
        index += 1;
    }
    if (!found)
        return false;
    list_pop(tile->drones, index);
    return true;
}
