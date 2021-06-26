/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** cmd_eject
*/

#include "server/request/handler.h"
#include "server/response/response.h"

void request_handler_cmd_eject(server_t *s, client_t *c, request_t *r)
{
    response_t *response = NULL;

    // Player gets ejected.
    client_add_response(c, response_create(RESPONSE_OK));
}
