/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace) [WSL: Ubuntu]
** File description:
** stop
*/

#include "simulation/simulation.h"

void simulation_stop(simulation_t *n)
{
    if (!n)
        return;
    if (n->map)
        destroy_map(n->map);
}