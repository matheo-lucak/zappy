/*
** EPITECH PROJECT, 2021
** server
** File description:
** eggs
*/

#include "logger/logger.h"
#include "simulation/simulation.h"
#include "server/response/response.h"
#include "server/server.h"

static void simulation_handle_egg_hatching(server_t *s,
                                        map_t *map,
                                        team_t *team,
                                        egg_t *egg)
{
    drone_t *drone = drone_create(egg->pos, false);

    if (!drone)
        return;
    drone->id = egg->id;
    team_add_drone(team, drone);
    map_add_drone(map, drone);
    server_log(LOG_SIMULATION_EGG_HATCHED, egg->pos.x, egg->pos.y);
    server_add_notification(s, response_create(RESPONSE_EHT, egg->id));
    team->free_slots_nb += 1;
}

static void simulation_handle_team_eggs(server_t *s, map_t *map, team_t *team)
{
    egg_t *egg = NULL;
    node_iterator_t *it = NULL;
    int idx_to_del = 0;

    for (it = list_iter_begin(team->eggs); it;) {
        egg = NODE_PTR(it, egg_t);
        if (egg->time_until_hatch <= 0) {
            idx_to_del = it->index;
            node_iter_next(&it);
            simulation_handle_egg_hatching(s, map, team, egg);
            list_pop(team->eggs, idx_to_del);
            continue;
        }
        egg->time_until_hatch -= 1;
        node_iter_next(&it);
    }
}

void simulation_handle_eggs(server_t *s)
{
    team_t *team = NULL;

    list_foreach(node, s->sim.teams) {
        team = NODE_PTR(node, team_t);
        simulation_handle_team_eggs(s, s->sim.map, team);
    }
}
