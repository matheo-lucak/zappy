/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** get_info
*/

#include <string.h>

#include "server/request/info.h"

const request_info_t *request_get_info_from_name(char *name)
{
    if (!name || !(*name))
        return NULL;
    for (size_t i = 0; i < request_info_map_size; i++) {
        if (!strcmp(name, request_info_map[i].name))
            return &request_info_map[i];
    }
    return NULL;
}