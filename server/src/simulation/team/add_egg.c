/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** add_egg
*/

#include "simulation/team.h"

bool team_add_egg(team_t *team, egg_t *egg)
{
    if (!egg)
        return false;
    return ptr_list_push_back(team->eggs, egg) == LIST_SUCCESS;
}
