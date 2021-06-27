/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** create
*/

#include <stdlib.h>

#include "logger/logger.h"
#include "simulation/drone.h"

drone_t *drone_create(int x, int y, bool activated)
{
    drone_t *new_drone = calloc(1, sizeof(drone_t));

    if (!new_drone)
        return NULL;
    new_drone->active = activated;
    new_drone->x = x;
    new_drone->y = y;
    new_drone->inventory = inventory_create();
    if (!new_drone->inventory) {
        drone_destroy(new_drone);
        return NULL;
    }
    inventory_add_item(new_drone->inventory,
        RESOURCE_FOOD, DRONE_DEFAULT_FOOD_QUANTITY);
    new_drone->facing_direction = direction_get_random();
    new_drone->elevation_lvl = DRONE_DEFAULT_ELEVATION_LVL;
    server_log(LOG_SIMULATION_NEW_DRONE, x, y, new_drone->facing_direction);
    return new_drone;
}
