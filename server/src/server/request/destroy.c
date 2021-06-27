/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** destroy
*/

#include <stdlib.h>

#include "server/request/request.h"

void request_destroy(request_t *request)
{
    if (!request)
        return;
    free(request->name);
    string_list_destroy(request->arguments);
    free(request);
}