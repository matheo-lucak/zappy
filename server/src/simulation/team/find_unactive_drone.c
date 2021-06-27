/*
** EPITECH PROJECT, 2021
** server
** File description:
** find_unactive_drone
*/

#include "simulation/team.h"

drone_t *team_find_unactive_drone(team_t *team)
{
    drone_t *drone = NULL;

    list_foreach(it, team->drones) {
        drone = NODE_PTR(it, drone_t);
        if (drone->active == false)
            return drone;
    }
    return NULL;
}
