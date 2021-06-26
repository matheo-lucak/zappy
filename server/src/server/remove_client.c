/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** remove_client
*/

#include "server/server.h"

static void server_remove_client_from_team(ptr_list_t *teams, drone_t *drone)
{
    team_t *team = NULL;

    list_foreach(team_node, teams) {
        team = NODE_PTR(team_node, team_t);
        if (team_delete_drone(team, drone))
            break;
    }
}

void server_remove_client(server_t *s, client_t *client)
{
    ptr_list_remove(s->clients, client);
    if (client->drone) {
        server_remove_client_from_team(s->s.teams, client->drone);
    }
}