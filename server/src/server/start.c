/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** start
*/

#include "server/server.h"

static int server_start_error(const char *error)
{
    epinet_perror(error);
    return SERVER_EXIT;
}

int server_start(const arguments_t *args, server_t *s)
{
    if (!s)
        return SERVER_EXIT;
    s->clients = generic_list_create(NULL/*//Client destructor*/);
    if (!s->clients)
        return SERVER_EXIT;
    s->selector = socket_selector_create();
    if (!s->selector)
        return server_start_error("");
    s->listener = tcp_listener_create();
    if (!s->listener)
        return server_start_error("");
    if (tcp_listener_listen(s->listener, args->port, IP_ADDRESS_ANY)
        == SOCKET_ERROR)
        return SERVER_EXIT;
    if (socket_selector_add_socket(s->selector, SOCKET(s->listener))
        == SOCKET_ERROR)
        return SERVER_EXIT;
    return SERVER_SUCCESS;
}