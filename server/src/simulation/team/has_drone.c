/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** has_drone
*/

#include "simulation/team.h"

bool team_has_drone(team_t *team, const drone_t *drone)
{
    return ptr_list_contains(team->drones, drone);
}
