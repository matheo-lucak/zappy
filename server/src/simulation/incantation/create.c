/*
** EPITECH PROJECT, 2021
** server
** File description:
** create
*/

#include <stdlib.h>

#include "simulation/incantation.h"

incantation_t *incantation_create(drone_t *owner, tile_t *tile)
{
    incantation_t *inc = NULL;

    if (!owner || !tile)
        return NULL;
    inc = malloc(sizeof(incantation_t));
    if (!inc)
        return NULL;
    inc->requirements = incantation_find_requirements(owner->elevation_lvl);
    inc->time_until_elevation = INCANTATION_TIME_TO_ELEVATE;
    inc->elevation_lvl = owner->elevation_lvl;
    inc->owner = owner;
    inc->tile = tile;
    if (!inc->requirements) {
        incantation_destroy(inc);
        return NULL;
    }
    return inc;
}