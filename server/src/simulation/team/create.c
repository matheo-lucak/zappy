/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** create
*/

#include <stdlib.h>
#include <string.h>

#include "simulation/team.h"

team_t *team_create(char *name, unsigned int free_slots_nb)
{
    team_t *team = malloc(sizeof(team_t));

    if (!team)
        return NULL;
    team->name = strdup(name ? name : TEAM_DEFAULT_NAME);
    team->free_slots_nb = free_slots_nb;
    team->drones = ptr_list_create((void *)&drone_destroy);
    if (!team->name || !team->drones) {
        team_destroy(team);
        return NULL;
    }
    return team;
}
