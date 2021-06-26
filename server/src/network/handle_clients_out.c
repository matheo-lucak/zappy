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

int network_handle_clients_out(server_t *s)
{
    selector_status_t status;
    response_t *response = NULL;
    char *r_data = NULL;
    size_t data_size = 0;
    bool left_to_send = false;

    do {
        left_to_send = false;
        status = socket_selector_wait(s->n.selector, 1, WATCH_WRT);
        if (status != SELECTOR_OK)
            return SERVER_ERROR;
        list_foreach(c, s->clients) {
            if (!socket_selector_is_socket_ready(s->n.selector, SOCKET(NODE_PTR(c, client_t)->socket)))
                continue;
            response = NODE_PTR(list_begin(NODE_PTR(c, client_t)->pending_responses), response_t);
            r_data = response->data;
            data_size = strlen(r_data);
            tcp_socket_send(NODE_PTR(c, client_t)->socket, r_data, data_size);
            list_pop_front(NODE_PTR(c, client_t)->pending_responses);
            if (!list_empty(NODE_PTR(c, client_t)->pending_responses))
                left_to_send = true;
        }
    } while (left_to_send);
    return SERVER_SUCCESS;
}
