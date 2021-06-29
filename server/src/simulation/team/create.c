/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** create
*/

#include <stdlib.h>
#include <string.h>

#include "simulation/team.h"

team_t *team_create(const char *name, unsigned int free_slots_nb)
{
    team_t *team = malloc(sizeof(team_t));

    if (!team)
        return NULL;
    team->default_slots_nb = free_slots_nb;
    team->free_slots_nb = free_slots_nb;
    team->name = strdup(name ? name : TEAM_DEFAULT_NAME);
    team->drones = ptr_list_create((node_dtor_t)&drone_destroy);
    team->eggs = ptr_list_create((node_dtor_t)&egg_destroy);
    if (!team->name || !team->drones || !team->eggs) {
        team_destroy(team);
        return NULL;
    }
    return team;
}
