/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** run
*/

#include "server/server.h"

int server_run(server_t *s)
{
    int status = SERVER_SUCCESS;

    s->is_running = true;
    while (s->is_running && status == SERVER_SUCCESS) {
        network_handle_clients_in(s);
        server_handle_request(s);
        status = network_handle_clients_out(s);
    }
    return status;
}
