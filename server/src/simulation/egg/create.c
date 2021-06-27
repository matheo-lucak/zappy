/*
** EPITECH PROJECT, 2021
** server
** File description:
** create
*/

#include <stdlib.h>

#include "logger/logger.h"
#include "simulation/egg.h"

egg_t *egg_create(int x, int y)
{
    egg_t *egg = malloc(sizeof(egg_t));

    if (!egg)
        return NULL;
    egg->x = x;
    egg->y = y;
    egg->time_until_hatch = EGG_TIME_TO_HATCH;
    server_log(LOG_SIMULATION_NEW_EGG, x, y);
    return egg;
}
