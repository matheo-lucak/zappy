/*
** EPITECH PROJECT, 2021
** server
** File description:
** block
*/

#include "logger/logger.h"

#include "server/client.h"

void client_block(client_t *client)
{
    server_log(LOG_SERVER_CLIENT_BLOCKED);
    client->blocked = true;
}

void client_unblock(client_t *client)
{
    server_log(LOG_SERVER_CLIENT_UNBLOCKED);
    client->blocked = false;
}
