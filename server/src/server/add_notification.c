/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** add_notification
*/

#include "server/server.h"
#include "server/response/response.h"

void server_add_notification(server_t *s, response_t *r)
{
    client_t *c = NULL;

    list_foreach(it, s->clients) {
        c = NODE_PTR(it, client_t);
        if (c->type == CLIENT_SPECTATOR) {
            client_add_response(c, response_clone(r));
        }
    }
    response_destroy(r);
}
