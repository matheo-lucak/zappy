/*
** EPITECH PROJECT, 2021
** server
** File description:
** clear_client
*/

#include "server/server.h"

void server_clear_clients(server_t *s)
{
    node_iterator_t *it = NULL;
    client_t *client = NULL;

    for (it = list_iter_begin(s->clients); it;) {
        client = NODE_PTR(it, client_t);
        node_iter_next(&it);
        if (client->status != CLIENT_ALIVE) {
            server_remove_client(s, client);
        }
    }
}
