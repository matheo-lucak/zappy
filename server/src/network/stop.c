/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** stop
*/

#include "server/server.h"

void network_stop(network_t *n)
{
    if (n->selector)
        socket_selector_destroy(n->selector);
    if (n->listener)
        tcp_listener_destroy(n->listener);
}