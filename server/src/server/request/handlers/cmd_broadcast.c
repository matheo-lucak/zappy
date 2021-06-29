/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** cmd_broadcast
*/

#include <stdlib.h>
#include <my.h>

#include "server/request/request.h"
#include "server/request/handler.h"
#include "server/response/response.h"

static char *broadcast_concat_message(request_t *r)
{
    char *m = NULL;
    char *buffer = NULL;

    list_foreach(node, r->arguments) {
        buffer = NODE_STR(node);
        m = my_str_cat(m, buffer, true, false);
        if (node->next)
            m = my_str_cat(m, " ", true, false);
    }
    return m;
}

void request_handler_cmd_broadcast(server_t *s, client_t *c, request_t *r)
{
    client_t *other = NULL;
    local_direction_t k = 0;
    char *m = NULL;

    if (list_empty(r->arguments)) {
        client_add_response(other, response_create(RESPONSE_KO));
        return;
    }
    m = broadcast_concat_message(r);
    list_foreach(node, s->clients) {
        other = NODE_PTR(node, client_t);
        if (!other->drone || !other->drone->active || other->drone == c->drone)
            continue;
        k = drone_get_sound_direction(c->drone, other->drone, s->sim.map);
        client_add_response(other, response_create(RESPONSE_BROADCAST, k, m));
    }
    free(m);
    client_add_response(c, response_create(RESPONSE_OK));
}
