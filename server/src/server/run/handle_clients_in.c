/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** handle_clients_in
*/

#include "server/server.h"

void server_handle_clients_in(server_t *s)
{
    handle_client_connection(s);
}