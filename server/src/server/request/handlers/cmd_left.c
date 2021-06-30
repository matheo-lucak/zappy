/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** cmd_left
*/

#include "server/request/handler.h"
#include "server/response/response.h"

void request_handler_cmd_left(__attribute__((unused)) server_t *s,
                            client_t *c,
                            __attribute__((unused)) request_t *r)
{
    drone_rotate(c->drone, LEFT);
    client_add_response(c, response_create(RESPONSE_OK));
}
