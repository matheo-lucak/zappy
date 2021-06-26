/*
** EPITECH PROJECT, 2021
** server
** File description:
** requirements
*/

#include "simulation/incantation.h"

const elevation_requirement_t elevation_requirements[] =
{
    {
        .drone_nb      = 1,
        .drone_lvl     = 1,
        .requirements   = {
            [RESOURCE_LINEMATE]     = 1,
            [RESOURCE_DERAUMERE]    = 0,
            [RESOURCE_SIBUR]        = 0,
            [RESOURCE_MENDIANE]     = 0,
            [RESOURCE_PHIRAS]       = 0,
            [RESOURCE_THYSTAME]     = 0,
        }
    },
    {
        .drone_nb      = 2,
        .drone_lvl     = 2,
        .requirements   = {
            [RESOURCE_LINEMATE]     = 1,
            [RESOURCE_DERAUMERE]    = 1,
            [RESOURCE_SIBUR]        = 1,
            [RESOURCE_MENDIANE]     = 0,
            [RESOURCE_PHIRAS]       = 0,
            [RESOURCE_THYSTAME]     = 0,
        }
    },
    {
        .drone_nb      = 2,
        .drone_lvl     = 3,
        .requirements   = {
            [RESOURCE_LINEMATE]     = 2,
            [RESOURCE_DERAUMERE]    = 0,
            [RESOURCE_SIBUR]        = 1,
            [RESOURCE_MENDIANE]     = 0,
            [RESOURCE_PHIRAS]       = 2,
            [RESOURCE_THYSTAME]     = 0,
        }
    },
    {
        .drone_nb      = 4,
        .drone_lvl     = 4,
        .requirements   = {
            [RESOURCE_LINEMATE]     = 1,
            [RESOURCE_DERAUMERE]    = 1,
            [RESOURCE_SIBUR]        = 2,
            [RESOURCE_MENDIANE]     = 0,
            [RESOURCE_PHIRAS]       = 1,
            [RESOURCE_THYSTAME]     = 0,
        }
    },
    {
        .drone_nb      = 4,
        .drone_lvl     = 5,
        .requirements   = {
            [RESOURCE_LINEMATE]     = 1,
            [RESOURCE_DERAUMERE]    = 2,
            [RESOURCE_SIBUR]        = 1,
            [RESOURCE_MENDIANE]     = 3,
            [RESOURCE_PHIRAS]       = 0,
            [RESOURCE_THYSTAME]     = 0,
        }
    },
    {
        .drone_nb      = 6,
        .drone_lvl     = 6,
        .requirements   = {
            [RESOURCE_LINEMATE]     = 1,
            [RESOURCE_DERAUMERE]    = 2,
            [RESOURCE_SIBUR]        = 3,
            [RESOURCE_MENDIANE]     = 0,
            [RESOURCE_PHIRAS]       = 1,
            [RESOURCE_THYSTAME]     = 0,
        }
    },
    {
        .drone_nb      = 6,
        .drone_lvl     = 7,
        .requirements   = {
            [RESOURCE_LINEMATE]     = 2,
            [RESOURCE_DERAUMERE]    = 2,
            [RESOURCE_SIBUR]        = 2,
            [RESOURCE_MENDIANE]     = 2,
            [RESOURCE_PHIRAS]       = 2,
            [RESOURCE_THYSTAME]     = 1,
        }
    },
};

const size_t elevation_requirements_size =
    sizeof(elevation_requirements) /
    sizeof(elevation_requirements[0]);
