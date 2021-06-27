/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** destroy
*/

#include <stdlib.h>

#include "server/client.h"

void client_destroy(client_t *c)
{
    if (!c)
        return;
    tcp_socket_destroy(c->socket);
    ptr_list_destroy(c->pending_requests);
    ptr_list_destroy(c->pending_responses);
    free(c);
}
