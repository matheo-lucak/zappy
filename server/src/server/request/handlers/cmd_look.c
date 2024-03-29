/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** cmd_look
*/

#include <stdlib.h>
#include "server/request/handler.h"
#include "server/response/response.h"

void request_handler_cmd_look(server_t *s,
                            client_t *c,
                            __attribute__((unused))request_t *r)
{
    char *look_format = NULL;

    look_format = drone_get_look_format(c->drone, s->sim.map);
    client_add_response(c, response_create(RESPONSE_LOOK, look_format));
    free(look_format);
}
