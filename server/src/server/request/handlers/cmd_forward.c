/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** cmd_forward
*/

#include "server/request/handler.h"
#include "server/response/response.h"

void request_handler_cmd_forward(server_t *s, client_t *c, request_t *r)
{
    response_t *response = NULL;

    drone_move(c->drone, s->s.map);
    client_add_response(c, response_create(RESPONSE_OK));
}
