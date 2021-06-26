/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** handle_clients.out
*/

#include <string.h>
#include <stdlib.h>
#include <epinet.h>
#include "server/server.h"
#include "server/response/response.h"

static bool network_handle_one_response_per_client(server_t *s)
{
    bool left_to_send = false;
    client_t *c = NULL;
    response_t *r = NULL;

    if (list_empty(s->clients))
        return false;
    list_foreach(node, s->clients) {
        c = NODE_PTR(node, client_t);
        if (!socket_selector_is_socket_ready(s->n.selector, SOCKET(c->socket)))
            continue;
        r = NODE_PTR(list_begin(c->pending_responses), response_t);
        tcp_socket_send(c->socket, r->data, strlen(r->data));
        list_pop_front(c->pending_responses);
        if (!list_empty(c->pending_responses))
            left_to_send = true;
    }
    return left_to_send;
}

int network_handle_clients_out(server_t *s)
{
    bool left_to_send = false;

    do {
        if (socket_selector_wait(s->n.selector, 1, WATCH_WRT) != SELECTOR_OK)
            return SERVER_ERROR;
        left_to_send = network_handle_one_response_per_client(s);
    } while (left_to_send);
    return SERVER_SUCCESS;
}
