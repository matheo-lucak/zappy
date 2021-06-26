/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** cmd_left
*/

#include "server/request/handler.h"
#include "server/response/response.h"

void request_handler_cmd_left(server_t *s, client_t *c, request_t *r)
{
    response_t *response = NULL;

    drone_rotate(c->drone, LEFT);
    response = response_create(RESPONSE_OK);
    generic_list_push_back(c->pending_responses, response, response_t *);
}
