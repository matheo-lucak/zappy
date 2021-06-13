/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** handle_clients_in
*/

#include "server/server.h"
#include "server/client.h"

void server_handle_clients_in(server_t *s)
{
    client_t *c = NULL;

    if (socket_selector_wait(s->n.selector, 500, WATCH_RD) <= 0)
        return;
    server_handle_client_connection(s);
    list_foreach(node, s->clients) {
        c = NODE_PTR(node, client_t);
        if (!c)
            continue;
        if (socket_selector_is_socket_ready(s->n.selector, SOCKET(c->socket))) {
        }
    }
}