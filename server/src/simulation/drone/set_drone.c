/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** set_drone
*/

#include "server/client.h"

void client_set_drone(client_t *client, drone_t *drone)
{
    if (!client)
        return;
    client->drone = drone;
}