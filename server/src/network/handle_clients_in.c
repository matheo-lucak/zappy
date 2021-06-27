/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** handle_clients_in
*/

#include <stdlib.h>

#include "server/server.h"
#include "server/client.h"
#include "server/request/request.h"

static void network_handle_client_input_from_socket(server_t *s, client_t *c)
{
    char *c_input = NULL;
    request_t *c_request = NULL;

    if (socket_selector_is_socket_ready(s->n.selector, SOCKET(c->socket))) {
        c_input = request_get_input(c);
        if (list_len(c->pending_requests) < CLIENT_MAX_PENDING_REQUEST) {
            c_request = request_parse_from_input(c_input, c->type);
            client_add_request(c, c_request);
        }
        free(c_input);
    }
}

void network_handle_clients_in(server_t *s)
{
    client_t *c = NULL;

    if (socket_selector_wait(s->n.selector, 1, WATCH_RD) <= 0)
        return;
    network_handle_client_connection(s);
    list_foreach(node, s->clients) {
        c = NODE_PTR(node, client_t);
        network_handle_client_input_from_socket(s, c);
    }
}