/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** create
*/

#include <stdlib.h>

#include "logger/logger.h"
#include "simulation/drone.h"

drone_t *drone_create(vector2u_t position, bool activated)
{
    drone_t *d = calloc(1, sizeof(drone_t));

    if (!d)
        return NULL;
    d->active = activated;
    d->pos = position;
    d->facing_direction = direction_get_random();
    d->elevation_lvl = DRONE_DEFAULT_ELEVATION_LVL;
    d->inventory = inventory_create();
    if (!d->inventory) {
        drone_destroy(d);
        return NULL;
    }
    inventory_add_item(d->inventory,
        RESOURCE_FOOD, DRONE_DEFAULT_FOOD_QUANTITY);
    server_log(LOG_SIMULATION_NEW_DRONE, d->pos.x, d->pos.y,
                                        d->facing_direction);
    return d;
}
