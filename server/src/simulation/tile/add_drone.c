/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** add_player
*/

#include <stdbool.h>
#include "simulation/tile.h"
#include "simulation/drone.h"

bool tile_add_drone(tile_t *tile, drone_t *drone)
{
    if (ptr_list_contains(tile->drones, drone))
        return false;
    return ptr_list_push_back(tile->drones, drone);
}
