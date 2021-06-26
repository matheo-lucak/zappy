/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** create
*/

#include <stdlib.h>

#include "simulation/drone.h"

drone_t *drone_create(int x, int y)
{
    drone_t *new_drone = calloc(1, sizeof(drone_t));

    if (!new_drone)
        return NULL;
    new_drone->x = x;
    new_drone->y = y;
    new_drone->inventory = inventory_create();
    new_drone->facing_direction = direction_get_random();
    return new_drone;
}
