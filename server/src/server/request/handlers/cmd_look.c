/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** cmd_look
*/

#include <stdlib.h>
#include "server/request/handler.h"
#include "server/response/response.h"

void request_handler_cmd_look(server_t *s, client_t *c, request_t *r)
{
    char *look_format = NULL;

    look_format = drone_get_look_format(s->s.map, c->drone);
    client_add_response(c, response_create(RESPONSE_LOOK, look_format));
    free(look_format);
}
