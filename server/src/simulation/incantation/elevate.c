/*
** EPITECH PROJECT, 2021
** server
** File description:
** elevate
*/

#include "simulation/incantation.h"

void incantation_elevate(incantation_t *inc)
{
    drone_t *drone = NULL;

    list_foreach(it, inc->tile->drones) {
        drone = NODE_PTR(it, drone_t);
        if (drone->elevation_lvl < ELEVATION_MAX_LVL)
            drone->elevation_lvl += 1;
    }
    for (resource_type_t t = RESOURCE_FOOD; t < RESOURCE_NB; t++) {
        for (size_t i = 0; i < inc->requirements->resources[t]; i++) {
            tile_remove_item(inc->tile, t);
        }
    }
}
