/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** stop
*/

#include "server/server.h"

void server_stop(server_t *s)
{
    if (s->clients)
        ptr_list_destroy(s->clients);
    network_stop(&s->n);
    simulation_stop(&s->s);
    server_log(LOG_SERVER_STOPPED);
}
