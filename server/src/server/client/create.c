/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** create
*/

#include <stdlib.h>

#include "server/client.h"

client_t *client_create(void)
{
    client_t *client = calloc(1, sizeof(client_t));

    if (!client)
        return NULL;
    client->drone = drone_create(0, 0);
    client->socket = tcp_socket_create();
    if (!client->drone || !client->socket) {
        client_destroy(client);
        return NULL;
    }
    return client;
}
