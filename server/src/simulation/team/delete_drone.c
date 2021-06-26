/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** add_drone
*/

#include "simulation/team.h"

bool team_delete_drone(team_t *team, drone_t *drone)
{
    const node_t *drone_node = NULL;

    if (!team || !team->drones || !drone)
        return false;
    drone_node = ptr_list_find(team->drones, drone);
    if (!drone_node)
        return false;
    list_pop(team->drones, drone_node->index);
    return true;
}
