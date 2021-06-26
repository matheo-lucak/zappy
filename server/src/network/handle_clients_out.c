/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** handle_clients.out
*/

#include <string.h>
#include <stdlib.h>
#include "server/server.h"
#include "server/response/response.h"

void network_handle_clients_out(server_t *s)
{
    char *r_data = NULL;
    size_t data_size = 0;

    list_foreach(c, s->clients) {
        list_foreach(r, NODE_PTR(c, client_t)->pending_responses) {
            r_data = NODE_PTR(r, response_t)->data;
            data_size = strlen(r_data);
            tcp_socket_send(NODE_PTR(c, client_t)->socket, r_data, data_size);
        }
        generic_list_destroy(NODE_PTR(c, client_t)->pending_responses);
        NODE_PTR(c, client_t)->pending_responses = generic_list_create(&free);
    }
}
