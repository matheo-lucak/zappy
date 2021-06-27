/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
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
    client->drone = NULL;
    client->socket = tcp_socket_create();
    client->pending_requests =  ptr_list_create(
                                (node_dtor_t)&request_destroy);
    client->pending_responses = ptr_list_create(
                                (node_dtor_t)&response_destroy);
    client->type = CLIENT_UNKNOWN;
    if (!client->socket ||
        !client->pending_requests ||
        !client->pending_responses) {
        client_destroy(client);
        return NULL;
    }
    return client;
}
