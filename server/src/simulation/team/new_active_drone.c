/*
** EPITECH PROJECT, 2021
** server
** File description:
** new_active_drone
*/

#include "simulation/team.h"
#include "simulation/simulation.h"

drone_t *team_new_active_drone(team_t *team, vector2u_t pos)
{
    drone_t *drone = team_find_unactive_drone(team);

    if (team->free_slots_nb <= 0)
        return NULL;
    if (!drone) {
        drone = drone_create(pos, true);
        if (!team_add_drone(team, drone)) {
            drone_destroy(drone);
            return NULL;
        }
        drone->id = get_next_entity_id();
    }
    team->free_slots_nb -= 1;
    return drone;
}