/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** remove_client
*/

#include "server/server.h"

void server_remove_client(server_t *s, client_t *client)
{

    network_remove_connection(&s->n, client);
    simulation_remove_drone(&s->sim, client->drone);
    ptr_list_remove(s->clients, client);
}