/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** add_drone
*/

#include "simulation/team.h"

bool team_add_drone(team_t *team, drone_t *drone)
{
    if (!drone)
        return false;
    return ptr_list_push_back(team->drones, drone) == LIST_SUCCESS;
}
