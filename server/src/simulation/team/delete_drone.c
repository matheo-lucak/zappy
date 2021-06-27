/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** add_drone
*/

#include "simulation/team.h"

bool team_delete_drone(team_t *team, drone_t *drone)
{
    if (!team || !team->drones)
        return false;
    if (ptr_list_remove(team->drones, drone) == LIST_ERROR)
        return false;
    if (team->free_slots_nb > team->default_slots_nb)
        team->free_slots_nb -= 1;
    return true;
}
