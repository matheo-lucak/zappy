/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** start
*/

#include <stdlib.h>

#include "server/server.h"
#include "server/client.h"

int server_start(const arguments_t *args, server_t *s)
{
    if (!s || !args)
        return SERVER_EXIT;
    memset(s, 0, sizeof(server_t));
    s->clients = ptr_list_create((void *)&client_destroy);
    if (!s->clients)
        return SERVER_EXIT;
    if (network_start(args, &s->n) != NETWORK_SUCCESS)
        return SERVER_EXIT;
    if (simulation_start(args, &s->s) != SIMULATION_SUCCESS)
        return SERVER_EXIT;
    server_log(LOG_SERVER_STARTED);
    return SERVER_SUCCESS;
}
