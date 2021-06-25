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
    const node_t *node = NULL;
    const node_t *node_to_delete = NULL;

    for (node = list_begin(team->eggs); node;) {
        egg = NODE_PTR(node, egg_t);
        if (egg->time_until_hatch <= 0) {
            node_to_delete = node;
            node = node->next;
            team_add_drone(team, drone_create(egg->x, egg->y, false));
            server_log(LOG_SIMULATION_EGG_HATCHED, egg->x, egg->y);
            team->free_slots_nb += 1;
            list_pop(team->eggs, node_to_delete->index);
            continue;
        }
        egg->time_until_hatch -= 1;
        node = (node)->next;
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
