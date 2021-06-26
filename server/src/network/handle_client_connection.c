/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** handle_client_connection
*/

#include "server/client.h"
#include "server/server.h"

void network_handle_client_connection(server_t *s)
{
    client_t *c = NULL;
    network_t *n = &s->n;

    if (socket_selector_is_socket_ready(n->selector,
                                        SOCKET(n->listener)) == false)
        return;
    if (!(c = client_create()))
        return;
    if (tcp_listener_accept(n->listener, &c->socket) == SOCKET_ERROR) {
        epinet_perror(NULL);
        return;
    }
    if (ptr_list_push_front(s->clients, c) == LIST_ERROR)
        client_destroy(c);
    socket_selector_add_socket(n->selector, SOCKET(n->listener));
    server_log(LOG_SERVER_NEW_CLIENT,
                tcp_socket_get_local_address(c->socket).str_address);
}
