/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** destroy
*/

#include <stdlib.h>

#include "simulation/drone.h"

void drone_destroy(drone_t *d)
{
    if (!d)
        return;
    inventory_destroy(d->inventory);
    free(d);
}
