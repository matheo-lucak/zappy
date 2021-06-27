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
    return ptr_list_remove(tile->drones, drone) == LIST_SUCCESS;
}
