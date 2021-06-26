/*
** EPITECH PROJECT, 2021
** server
** File description:
** create
*/

#include <stdlib.h>

#include "simulation/incantation.h"

incantation_t *incantation_create(drone_t *owner)
{
    incantation_t *inc = NULL;

    if (!owner)
        return NULL;
    inc = malloc(sizeof(incantation_t));
    if (!inc)
        return NULL;
    inc->owner = owner;
    inc->time_until_elevation = INCANTATION_TIME_TO_ELEVATE;
    inc->requirements = incantation_find_requirements(owner->elevation_lvl);
    if (!inc->requirements) {
        incantation_destroy(inc);
        return NULL;
    }
    return inc;
}