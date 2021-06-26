/*
** EPITECH PROJECT, 2021
** server
** File description:
** check
*/

#include "simulation/incantation.h"


static bool incantation_check_drone_lvl(incantation_t *inc, tile_t *tile)
{
    drone_t *drone = NULL;

    list_foreach(it, tile->drones) {
        drone = NODE_PTR(it, drone_t);
        if (drone->elevation_lvl != inc->requirements->drone_lvl)
            return false;
    }
    return true;
}

static bool incantation_check_drone_count(incantation_t *inc, tile_t *tile)
{
    return inc->requirements->drone_nb == tile_count_drone(tile);
}

static bool incantation_check_item_count(incantation_t *inc, tile_t *tile)
{
    for (resource_type_t t = RESOURCE_FOOD + 1; t != RESOURCE_NB; t++) {
        if (inc->requirements->resources[t] != tile_count_item(tile, t))
            return false;
    }
    return true;
}

bool incantation_check_requirements(incantation_t *inc, tile_t *tile)
{
    if (!inc || !inc->requirements || !tile)
        return false;
    if (incantation_check_drone_lvl(inc, tile) == false)
        return false;
    if (incantation_check_drone_count(inc, tile) == false)
        return false;
    if (incantation_check_item_count(inc, tile) == false)
        return false;
    return true;
}