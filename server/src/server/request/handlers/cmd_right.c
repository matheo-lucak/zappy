/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** cmd_right
*/

#include "server/request/handler.h"
#include "server/response/response.h"

void request_handler_cmd_right(server_t *s, client_t *c, request_t *r)
{
    drone_rotate(c->drone, RIGHT);
    client_add_response(c, response_create(RESPONSE_OK));
}
