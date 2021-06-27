/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
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
