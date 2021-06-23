/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** to
*/

#include "logger/logger.h"
#include "server/client.h"

void client_to_drone(client_t *client, drone_t *drone)
{
    if (!client)
        return;
    if (client->type != CLIENT_UNKNOWN) {
        server_log(LOG_SERVER_CLIENT_TO_ERROR);
        return;
    }
    client->drone = drone;
    client->type = CLIENT_DRONE;
    server_log(LOG_SERVER_CLIENT_TO_DRONE);
}

void client_to_spectator(client_t *client)
{
    if (!client)
        return;
    if (client->type != CLIENT_UNKNOWN) {
        server_log(LOG_SERVER_CLIENT_TO_ERROR);
        return;
    }
    client->type = CLIENT_SPECTATOR;
    server_log(LOG_SERVER_CLIENT_TO_SPECTATOR);
}