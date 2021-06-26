/*
** EPITECH PROJECT, 2021
** server
** File description:
** find_team_from_drone
*/

#include "simulation/simulation.h"

team_t *simulation_find_team_from_drone(simulation_t *sim, drone_t *drone)
{
    team_t *team = NULL;

    if (!drone)
        return NULL;
    list_foreach(node, sim->teams) {
        team = NODE_PTR(node, team_t);
        if (team_has_drone(team, drone) == true)
            return team;
    }
    return NULL;
}