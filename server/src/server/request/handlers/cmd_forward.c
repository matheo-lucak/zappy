/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** cmd_forward
*/

#include "server/request/handler.h"
#include "server/response/response.h"

void request_handler_cmd_forward(server_t *s,
                                client_t *c,
                                __attribute__((unused))request_t *r)
{
    drone_move(c->drone, s->sim.map);
    client_add_response(c, response_create(RESPONSE_OK));
}
