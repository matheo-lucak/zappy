/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** handle_client_connection
*/

#include "server/client.h"
#include "server/server.h"

void server_handle_client_connection(server_t *s)
{
    client_t *new_client = NULL;
    network_t *n = &s->n;

    if (socket_selector_is_socket_ready(n->selector, SOCKET(n->listener))
        == false)
        return;
    new_client = client_create();
    if (!new_client)
        return;
    if (tcp_listener_accept(n->listener, &new_client->socket) == SOCKET_ERROR) {
        epinet_perror(NULL);
        return;
    }
    if (ptr_list_push_front(s->clients, new_client) == LIST_ERROR)
        client_destroy(new_client);
    socket_selector_add_socket(n->selector, SOCKET(new_client->socket));
}