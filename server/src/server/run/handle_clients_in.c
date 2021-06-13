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
    client_t *client = NULL;

    if (socket_selector_wait(s->selector, 500, WATCH_RD) <= 0)
        return;
    handle_client_connection(s);
    list_foreach(node, s->clients) {
        client = NODE_PTR(node, client_t);
        if (!client)
            continue;
        if (socket_selector_is_socket_ready(s->selector, client->socket)) {
            //
        }
    }
}