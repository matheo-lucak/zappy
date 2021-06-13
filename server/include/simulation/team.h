/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** team
*/

#ifndef TEAM_H_
#define TEAM_H_

#include <mylist.h>

#include "server/client.h"
#include "simulation/drone.h"

typedef struct player_s
{
    drone_t drone;
    client_t *client;
} player_t;

typedef struct team_s
{
    char *          name;
    unsigned int    free_slots_nb;
    ptr_list_t *    players;
} team_t;


void team_add_player(team_t *team, drone_t *drone);

#endif /* !TEAM_H_ */
