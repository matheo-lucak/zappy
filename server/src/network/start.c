/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** start
*/
#include <epinet.h>
#include "server/server.h"
#include "server/client.h"

static int network_start_error(const char *error)
{
    epinet_perror(error ? error : "");
    return NETWORK_EXIT;
}

int network_start(const arguments_t *args, network_t *n)
{
    n->selector = socket_selector_create();
    n->listener = tcp_listener_create();
    if (!n->selector || !n->listener)
        return network_start_error(NULL);
    if (tcp_listener_listen(n->listener, args->port, IP_ADDRESS_ANY)
                                                    == SOCKET_ERROR)
        return network_start_error(NULL);
    if (socket_selector_add_socket(n->selector, SOCKET(n->listener))
                                                    == SOCKET_ERROR)
        return network_start_error(NULL);
    server_log(LOG_NETWORK_STARTED);
    server_log(LOG_NETWORK_LISTENING, tcp_socket_get_local_port(n->listener));
    return NETWORK_SUCCESS;
}
