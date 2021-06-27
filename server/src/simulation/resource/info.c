/*
** EPITECH PROJECT, 2021
** server
** File description:
** info
*/

#include "simulation/resources.h"

const resource_info_t resource_infos[] = {
    {.name = "food",        .type = RESOURCE_FOOD,        .density = .5f},
    {.name = "linemate",    .type = RESOURCE_LINEMATE,    .density = .3f},
    {.name = "deraumere",   .type = RESOURCE_DERAUMERE,   .density = .15f},
    {.name = "sibur",       .type = RESOURCE_SIBUR,       .density = .1f},
    {.name = "mendiane",    .type = RESOURCE_MENDIANE,    .density = .1f},
    {.name = "phiras",      .type = RESOURCE_PHIRAS,      .density = .08f},
    {.name = "thystame",    .type = RESOURCE_THYSTAME,    .density = .05f},
};

const size_t resource_infos_size =
    sizeof(resource_infos) /sizeof(resource_infos[0]);
