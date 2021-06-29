/*
** EPITECH PROJECT, 2021
** Zappy
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
    ptr_list_destroy(team->drones);
    ptr_list_destroy(team->eggs);
    free(team->name);
    free(team);
}
