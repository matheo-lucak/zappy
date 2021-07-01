/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** create
*/

#include <stdlib.h>

#include "server/client.h"
#include "server/request/request.h"
#include "server/response/response.h"

client_t *client_create(void)
{
    client_t *client = calloc(1, sizeof(client_t));

    if (!client)
        return NULL;
    client->type = CLIENT_UNKNOWN;
    client->status = CLIENT_ALIVE;
    client->blocked = false;
    client->socket = tcp_socket_create();
    client->input_stock = NULL;
    client->drone = NULL;
    client->pending_requests = ptr_list_create(
                                (node_dtor_t)&request_destroy);
    client->pending_responses = ptr_list_create(
                                (node_dtor_t)&response_destroy);
    if (!client->socket
        || !client->pending_requests
        || !client->pending_responses) {
        client_destroy(client);
        return NULL;
    }
    return client;
}
