/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** start
*/

#include <stdlib.h>
#include <string.h>

#include "server/server.h"
#include "server/client.h"

int server_start(const arguments_t *args, server_t *s)
{
    if (!s || !args)
        return SERVER_EXIT;
    memset(s, 0, sizeof(server_t));
    s->freq = args->freq;
    s->clients = ptr_list_create((node_dtor_t)&client_destroy);
    if (!s->clients)
        return SERVER_EXIT;
    if (network_start(args, &s->n) != NETWORK_SUCCESS)
        return SERVER_EXIT;
    if (simulation_start(args, &s->sim) != SIMULATION_SUCCESS)
        return SERVER_EXIT;
    server_log(LOG_SERVER_STARTED);
    return SERVER_SUCCESS;
}
