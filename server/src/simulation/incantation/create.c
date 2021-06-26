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
    incantation_t *incantation = NULL;

    if (!owner)
        return NULL;
    incantation = malloc(sizeof(incantation));
    if (!incantation)
        return NULL;
    incantation->owner = owner;
    incantation->time_until_elevation = INCANTATION_TIME_TO_ELEVATE;
    return incantation;
}