/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
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