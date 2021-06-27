/*
** EPITECH PROJECT, 2021
** server
** File description:
** eggs
*/

#include "logger/logger.h"
#include "simulation/simulation.h"

static void simulation_handle_team_eggs(team_t *team)
{
    egg_t *egg = NULL;
    node_iterator_t *it = NULL;
    int idx_to_del = 0;

    for (it = list_iter_begin(team->eggs); it;) {
        egg = NODE_PTR(it, egg_t);
        if (egg->time_until_hatch <= 0) {
            idx_to_del = it->index;
            node_iter_next(&it);
            team_add_drone(team, drone_create(egg->x, egg->y, false));
            server_log(LOG_SIMULATION_EGG_HATCHED, egg->x, egg->y);
            team->free_slots_nb += 1;
            list_pop(team->eggs, idx_to_del);
            continue;
        }
        egg->time_until_hatch -= 1;
        node_iter_next(&it);
    }
}

void simulation_handle_eggs(simulation_t *sim)
{
    team_t *team = NULL;

    list_foreach(node, sim->teams) {
        team = NODE_PTR(node, team_t);
        simulation_handle_team_eggs(team);
    }
}
