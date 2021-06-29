/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** create
*/

#include <stdlib.h>

#include "server/request/request.h"

request_t *request_create(void)
{
    request_t *request = calloc(1, sizeof(request_t));

    if (!request)
        return NULL;
    request->arguments = string_list_create();
    if (!request->arguments) {
        request_destroy(request);
        return NULL;
    }
    request->is_valid = false;
    return request;
}
