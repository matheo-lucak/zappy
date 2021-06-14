/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** is_spectator
*/

#include "server/client.h"

bool client_is_spectator(client_t *client)
{
    if (!client)
        return false;
    return client->drone == NULL;
}
