/*
** EPITECH PROJECT, 2021
** server
** File description:
** remove_connection
*/

#include "logger/logger.h"

#include "network/network.h"
#include "server/client.h"

void network_remove_connection(network_t *n, client_t *c)
{
    socket_selector_remove_socket(n->selector, SOCKET(c->socket));
    server_log(LOG_NETWORK_CLIENT_LEFT, c->id);
}