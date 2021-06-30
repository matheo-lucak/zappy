/*
** EPITECH PROJECT, 2021
** server
** File description:
** handle
*/

#include "server/server.h"
#include "simulation/simulation.h"

void simulation_handle(server_t *s)
{
    map_refill(s->sim.map);
    simulation_handle_eggs(s);
    simulation_handle_incantation(s);
    simulation_handle_food(s);
}
