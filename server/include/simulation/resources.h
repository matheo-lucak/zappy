/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** resources
*/

#ifndef RESOURCES_H_
#define RESOURCES_H_

#include <stddef.h>

typedef enum resource_type_s
{
    RESOURCE_FOOD,
    RESOURCE_LINEMATE,
    RESOURCE_DERAUMERE,
    RESOURCE_SIBUR,
    RESOURCE_MENDIANE,
    RESOURCE_PHIRAS,
    RESOURCE_THYSTAME,

    // This enumerate must stay the last
    RESOURCE_NB
} resource_type_t;

typedef float density_t;

typedef struct resource_info_s
{
    char *          name;
    resource_type_t type;
    density_t       density;
} resource_info_t;

extern const resource_info_t resource_infos[];
extern const size_t resource_infos_size;

const resource_info_t *resource_get_info_from_name(char *name);
const resource_info_t *resource_get_info_from_type(resource_type_t type);

#endif /* !RESOURCES_H_ */
