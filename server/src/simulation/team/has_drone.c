/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** has_drone
*/

#include "simulation/team.h"

bool team_has_drone(team_t *team, const drone_t *drone)
{
    if (!team || !team->drones || !drone)
        return false;
    return ptr_list_find(team->drones, drone) ? true : false;
}
