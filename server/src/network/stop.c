/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** stop
*/

#include "server/server.h"

void network_stop(network_t *n)
{
    socket_selector_destroy(n->selector);
    tcp_listener_destroy(n->listener);
    server_log(LOG_NETWORK_STOPPED);
}