/*
** EPITECH PROJECT, 2021
** server
** File description:
** new_active_drone
*/

#include "simulation/team.h"

drone_t *team_new_active_drone(team_t *team, vector2u_t pos)
{
    drone_t *drone = team_find_unactive_drone(team);

    if (drone) {
        drone->active = true;
        team->free_slots_nb -= 1;
        return drone;
    }
    drone = drone_create(pos, true);
    team_add_drone(team, drone);
    return drone;
}