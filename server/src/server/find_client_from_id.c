/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** find_client_from_id
*/

#include "server/server.h"

client_t *server_find_client_from_id(server_t *s, unsigned id)
{
    client_t *c = NULL;

    list_foreach(it, s->clients) {
        c = NODE_PTR(it, client_t);
        if (c->id == id) {
            node_iter_end(&it);
            return c;
        }
    }
    return NULL;
}