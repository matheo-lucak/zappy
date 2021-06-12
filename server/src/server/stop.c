/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** stop
*/

#include "server/server.h"

void server_stop(server_t *s)
{
    if (s->selector)
        socket_selector_destroy(s->selector);
    if (s->listener)
        tcp_listener_destroy(s->listener);
    generic_list_destroy(s->clients);
}
