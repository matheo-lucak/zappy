/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** add_drone
*/

#include "simulation/team.h"

bool team_add_drone(team_t *team, drone_t *drone)
{
    if (!team || !team->drones || !drone)
        return false;
    if (team->free_slots_nb == 0)
        return false;
    if (drone->active)
        team->free_slots_nb -= 1;
    return (ptr_list_push_back(team->drones, drone) == LIST_SUCCESS
    ? true
    : false);
}
