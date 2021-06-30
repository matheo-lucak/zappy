/*
** EPITECH PROJECT, 2021
** Zappy
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
    free(c->input_stock);
    ptr_list_destroy(c->pending_requests);
    ptr_list_destroy(c->pending_responses);
    free(c);
}
