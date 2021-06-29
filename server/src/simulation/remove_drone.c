/*
** EPITECH PROJECT, 2021
** server
** File description:
** remove_drone
*/

#include "simulation/incantation.h"
#include "simulation/simulation.h"

static void simulation_remove_client_from_incantation(simulation_t *sim,
                                                    drone_t *drone)
{
    incantation_t *inc = NULL;

    list_foreach(it, sim->incantations) {
        inc = NODE_PTR(it, incantation_t);
        if (inc->owner == drone) {
            incantation_remove_owner(inc);
        }
    }
}

static void simulation_remove_client_from_map(simulation_t *sim,
                                                drone_t *drone)
{
    tile_t *tile = sim->map->tiles[drone->pos.y][drone->pos.x];

    tile_remove_drone(tile, drone);
}

static void simulation_remove_client_from_team(simulation_t *sim,
                                                drone_t *drone)
{
    team_t *team = NULL;

    list_foreach(team_node, sim->teams) {
        team = NODE_PTR(team_node, team_t);
        if (team_delete_drone(team, drone))
            break;
    }
}

void simulation_remove_drone(simulation_t *sim, drone_t *drone)
{
    if (!drone)
        return;
    simulation_remove_client_from_map(sim, drone);
    simulation_remove_client_from_incantation(sim, drone);
    simulation_remove_client_from_team(sim, drone);
}