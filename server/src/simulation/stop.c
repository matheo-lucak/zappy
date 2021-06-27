/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace) [WSL: Ubuntu]
** File description:
** stop
*/

#include "logger/logger.h"
#include "simulation/simulation.h"

void simulation_stop(simulation_t *n)
{
    if (!n)
        return;
    if (n->map)
        map_destroy(n->map);
    server_log(LOG_SIMULATION_STOPPED);
}