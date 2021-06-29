/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** handle_clients_in
*/

#include <errno.h>
#include <stdlib.h>

#include "server/server.h"
#include "server/client.h"
#include "server/request/request.h"

static void network_handle_one_input_per_client(server_t *s, client_t *c)
{
    socket_status_t status = SOCKET_DONE;

    if (!socket_selector_is_socket_ready(s->n.selector, SOCKET(c->socket)))
        return;
    status = network_get_input_stock(c);
    if (status == SOCKET_ERROR || status == SOCKET_DISCONNECTED)
        c->alive = false;
}

void network_handle_clients_in(server_t *s)
{
    client_t *c = NULL;
    socket_status_t status = 0;

    status = socket_selector_wait(s->n.selector, 1, WATCH_RD);
    if (status == SOCKET_ERROR && (errno == EBADF || errno == EINVAL)) {
        epinet_perror("Socket selector WATCH_RD failed");
        s->status = SERVER_ERROR;
        return;
    } else if (status == 0)
        return;
    network_handle_client_connection(s);
    list_foreach(node, s->clients) {
        c = NODE_PTR(node, client_t);
        network_handle_one_input_per_client(s, c);
    }
}