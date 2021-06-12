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
    if (c->drone)
        drone_destroy(c->drone);
    if (c->socket)
        tcp_socket_destroy(c->socket);
    free(c);
}
