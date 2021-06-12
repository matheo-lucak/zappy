/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** start
*/

#include "server.h"

static int start_server_error(const char *error)
{
    epinet_perror(error);
    return -1;
}

int start_server(const arguments_t *args, server_t *s)
{
    if (!s)
        return 1;
    s->listener = tcp_listener_create();
    if (!s->listener)
        return start_server_error("");
    srv->selector = socket_selector_create();
    if (!srv->selector)
        return start_server_error("");
    srv->clients = generic_list_create();
    if (!srv->clients)
        return server_init_client_list_error();
    return 0;
}