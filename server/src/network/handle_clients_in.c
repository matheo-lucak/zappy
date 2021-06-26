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

void network_handle_clients_in(server_t *s)
{
    client_t *c = NULL;
    char *c_input = NULL;
    request_t *c_request = NULL;

    if (socket_selector_wait(s->n.selector, 500, WATCH_RD) <= 0)
        return;
    network_handle_client_connection(s);
    list_foreach(node, s->clients) {
        c = NODE_PTR(node, client_t);
        if (!c)
            continue;
        if (socket_selector_is_socket_ready(s->n.selector, SOCKET(c->socket))) {
            c_input = request_get_input(c);
            if (c->pending_requests->__c.size < CLIENT_MAX_PENDING_REQUEST) {
                c_request = request_parse_from_input(c_input, c->type);
                ptr_list_push_back(c->pending_requests, c_request);
            }
            free(c_input);
        }
    }
}