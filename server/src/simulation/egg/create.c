/*
** EPITECH PROJECT, 2021
** server
** File description:
** create
*/

#include <stdlib.h>

#include "simulation/simulation.h"
#include "logger/logger.h"
#include "simulation/egg.h"

egg_t *egg_create(vector2u_t pos)
{
    egg_t *egg = malloc(sizeof(egg_t));

    if (!egg)
        return NULL;
    egg->pos = pos;
    egg->time_until_hatch = EGG_TIME_TO_HATCH;
    egg->id = get_next_entity_id();
    server_log(LOG_SIMULATION_NEW_EGG, egg->pos.x, egg->pos.y);
    return egg;
}
