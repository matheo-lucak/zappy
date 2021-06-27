/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace) [WSL: Ubuntu]
** File description:
** start
*/

#include <string.h>

#include "logger/logger.h"
#include "simulation/simulation.h"
#include "simulation/incantation.h"

static void simulation_create_all_teams(const arguments_t *args,
                                                simulation_t *sim)
{
    char *team_name = NULL;
    team_t *team = NULL;

    if (!args->team_names)
        return;
    list_foreach(node, args->team_names) {
        team_name = NODE_STR(node);
        team = team_create(team_name, args->clients_nb);
        if (team)
            ptr_list_push_back(sim->teams, team);
    }
}

int simulation_start(const arguments_t *args, simulation_t *sim)
{
    if (!args || !sim)
        return SIMULATION_EXIT;
    sim->map = map_create(args->width, args->height);
    sim->teams = ptr_list_create((node_dtor_t)&team_destroy);
    sim->incantations = ptr_list_create((node_dtor_t)&incantation_destroy);
    if (!sim->map || !sim->teams || !sim->incantations)
        return SIMULATION_EXIT;
    sim->default_team_free_slot = args->clients_nb;
    simulation_create_all_teams(args, sim);
    server_log(LOG_SIMULATION_STARTED);
    return SIMULATION_SUCCESS;
}