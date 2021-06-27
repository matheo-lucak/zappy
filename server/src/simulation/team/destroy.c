/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** create
*/

#include <stdlib.h>
#include <string.h>

#include "simulation/team.h"

void team_destroy(team_t *team)
{
    if (!team)
        return;
    if (team->drones)
        ptr_list_destroy(team->drones);
    if (team->eggs)
        ptr_list_destroy(team->eggs);
    if (team->name)
        free(team->name);
    free(team);
}
