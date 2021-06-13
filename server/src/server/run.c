/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** run
*/

#include "server/server.h"

int server_run(server_t *s)
{
    int error = SERVER_SUCCESS;

    s->is_running = true;
    while (s->is_running)
    {
        server_handle_clients_in(s);
        server_handle_clients_out(s);
    }
    return error;
}
