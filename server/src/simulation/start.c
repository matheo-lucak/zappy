/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace) [WSL: Ubuntu]
** File description:
** start
*/

#include "simulation/simulation.h"

int simulation_start(const arguments_t *args, simulation_t *n)
{
    if (!args || !n)
        return SIMULATION_EXIT;
    n->map = map_create(args->width, args->height);
    if (!n->map)
        return SIMULATION_EXIT;
    n->default_team_free_slot = args->clients_nb;
    return SIMULATION_SUCCESS;
}