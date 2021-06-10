/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** resources
*/

#ifndef RESOURCES_H_
#define RESOURCES_H_

typedef enum resource_type_s
{
    RESOURCE_FOOD,
    RESOURCE_LINEMATE,
    RESOURCE_DERAUMERE,
    RESOURCE_SIBUR,
    RESOURCE_MENDIANE,
    RESOURCE_PHIRAS,
    RESOURCE_THYSTAME,
} resource_type_t;

typedef struct resource_info_s
{
    char *          name;
    resource_type_t type;
    float           density;
} resource_info_t;

//extern const resource_info_t resource_INFOS[];

static const resource_info_t resource_INFOS[] = {
    {.name = "food",        .type = RESOURCE_FOOD,        .density = .5f},
    {.name = "linemate",    .type = RESOURCE_LINEMATE,    .density = .3f},
    {.name = "deraumere",   .type = RESOURCE_DERAUMERE,   .density = .15f},
    {.name = "sibur",       .type = RESOURCE_SIBUR,       .density = .1f},
    {.name = "mendiane",    .type = RESOURCE_MENDIANE,    .density = .1f},
    {.name = "phiras",      .type = RESOURCE_PHIRAS,      .density = .08f},
    {.name = "thystame",    .type = RESOURCE_THYSTAME,    .density = .05f},
};

#endif /* !RESOURCES_H_ */
