/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
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
