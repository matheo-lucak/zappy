/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** handle_client_connection
*/

#include "server/client.h"
#include "server/server.h"

void handle_client_connection(server_t *s)
{
    client_t *new_client = NULL;

    if (socket_selector_is_socket_ready(s->selector, SOCKET(s->listener))
        == false)
        return;
    new_client = client_create();
    if (!new_client)
        return;
    if (tcp_listener_accept(s->listener, &new_client->socket) == SOCKET_ERROR) {
        epinet_perror("");
        return;
    }
    // APPEND CLIENT TO LIST
}