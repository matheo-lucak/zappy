/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** stop
*/

#include "server/server.h"

void server_stop(server_t *s)
{
    network_stop(&s->n);
    simulation_stop(&s->s);
}
