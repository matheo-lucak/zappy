/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** handle_clients.out
*/

#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <epinet.h>

#include "server/server.h"
#include "server/response/response.h"

static bool is_client_able_to_receive(server_t *s, client_t *c)
{
    if (list_empty(c->pending_responses))
        return false;
    if (c->alive == false)
        return false;
    if (!socket_selector_is_socket_ready(s->n.selector, SOCKET(c->socket)))
        return false;
    return true;
}

static bool network_handle_one_response_per_client(server_t *s)
{
    bool left_to_send = false;
    client_t *c = NULL;
    response_t *r = NULL;

    if (list_empty(s->clients))
        return false;
    list_foreach(node, s->clients) {
        c = NODE_PTR(node, client_t);
        if (!is_client_able_to_receive(s, c))
            continue;
        r = NODE_PTR(list_begin(c->pending_responses), response_t);
        if (tcp_socket_send(c->socket, r->data, strlen(r->data))
            == SOCKET_DISCONNECTED)
            c->alive = false;
        list_pop_front(c->pending_responses);
        if (!list_empty(c->pending_responses))
            left_to_send = true;
    }
    return left_to_send;
}

void network_handle_clients_out(server_t *s)
{
    bool left_to_send = false;
    socket_status_t status = 0;

    do {
        status = socket_selector_wait(s->n.selector, 1, WATCH_WRT);
        if (status == SOCKET_ERROR && (errno == EBADF || errno == EINVAL)) {
            epinet_perror("Socket selector WATCH_RD failed");
            s->status = SERVER_ERROR;
            return;
        } else if (status == 0)
            return;
        left_to_send = network_handle_one_response_per_client(s);
    } while (left_to_send);
}
