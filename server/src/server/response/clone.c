/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** clone
*/

#include <stdlib.h>
#include <string.h>

#include "server/response/response.h"

response_t *response_clone(response_t *other)
{
    response_t *response = NULL;

    if (!other)
        return NULL;
    response = malloc(sizeof(response_t));
    if (!response)
        return NULL;
    response->data = strdup(other->data);
    if (!response->data) {
        response_destroy(other);
        return NULL;
    }
    return response;
}
