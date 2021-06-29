/*
** EPITECH PROJECT, 2021
** server
** File description:
** find_team_from_drone
*/

#include "server/server.h"

client_t *server_find_client_from_drone(server_t *s, drone_t *drone)
{
    client_t *c = NULL;

    if (!drone)
        return NULL;
    list_foreach(it, s->clients) {
        c = NODE_PTR(it, client_t);
        if (c->drone == drone) {
            node_iter_end(&it);
            return c;
        }
    }
    return NULL;
}