/*
** EPITECH PROJECT, 2021
** server
** File description:
** get_info
*/

#include <string.h>

#include "simulation/resources.h"

const resource_info_t *resource_get_info_from_name(char *name)
{
    if (!name)
        return NULL;
    for (size_t i = 0; i < resource_infos_size; i++) {
        if (strcmp(resource_infos[i].name, name) == 0)
            return &resource_infos[i];
    }
    return NULL;
}

const resource_info_t *resource_get_info_from_type(resource_type_t type)
{
    for (size_t i = 0; i < resource_infos_size; i++) {
        if (resource_infos->type == type)
            return &resource_infos[i];
    }
    return NULL;
}
