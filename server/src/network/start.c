/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** start
*/

#include "server/server.h"
#include "server/client.h"

static int network_start_error(const char *error)
{
    epinet_perror(error);
    return NETWORK_EXIT;
}

int network_start(const arguments_t *args, network_t *n)
{
    n->selector = socket_selector_create();
    if (!n->selector)
        return network_start_error(NULL);
    n->listener = tcp_listener_create();
    if (!n->listener)
        return network_start_error(NULL);
    if (tcp_listener_listen(n->listener, args->port, IP_ADDRESS_ANY) == SOCKET_ERROR)
        return network_start_error(NULL);
    if (socket_selector_add_socket(n->selector, SOCKET(n->listener)) == SOCKET_ERROR)
        return network_start_error(NULL);
    return SERVER_SUCCESS;
}