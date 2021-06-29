/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** cmd_broadcast
*/

#include <stdlib.h>
#include <my.h>

#include "server/request/request.h"
#include "server/request/handler.h"
#include "server/response/response.h"

void request_handler_cmd_broadcast(server_t *s, client_t *c, request_t *r)
{
    client_t *other = NULL;
    local_direction_t k = 0;
    char *m = NULL;
    char *buffer = NULL;

    list_foreach(node, r->arguments) {
        buffer = NODE_STR(node);
        m = my_str_cat(m, buffer, true, true);
        if (node->next)
            m = my_str_cat(m, " ", true, false);
    }
    list_foreach(node, s->clients) {
        other = NODE_PTR(node, client_t);
        if (!other->drone || !other->drone->active || other->drone == c->drone)
            continue;
        k = drone_get_sound_direction(s->sim.map, c->drone, other->drone);
        client_add_response(other, response_create(RESPONSE_BROADCAST, k, m));
    }
    free(m);
    client_add_response(c, response_create(RESPONSE_OK));
}
