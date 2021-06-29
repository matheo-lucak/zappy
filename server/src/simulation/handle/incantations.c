/*
** EPITECH PROJECT, 2021
** server
** File description:
** incantations
*/

#include "server/server.h"
#include "simulation/simulation.h"
#include "simulation/incantation.h"
#include "server/response/response.h"

static void simulation_handle_single_incantation(server_t *s,
                                            incantation_t *inc)
{
    client_t *client = server_find_client_from_drone(s, inc->owner);

    if (!client || !incantation_check_requirements(inc)) {
        list_foreach(it, inc->tile->drones) {
            client = server_find_client_from_drone(s, NODE_PTR(it, drone_t));
            if (client)
                client_add_response(client, response_create(RESPONSE_KO));
        }
        return;
    }
    client_unblock(client);
    incantation_elevate(inc);
    list_foreach(it, inc->tile->drones) {
        client = server_find_client_from_drone(s, NODE_PTR(it, drone_t));
        if (client) {
            client_add_response(client,
                response_create(RESPONSE_ELEVATION, inc->elevation_lvl + 1));
        }
    }
}

void simulation_handle_incantation(server_t *s)
{
    incantation_t *inc = NULL;
    node_iterator_t *it = NULL;
    int idx_to_del = 0;

    for (it = list_iter_begin(s->sim.incantations); it;) {
        inc = NODE_PTR(it, incantation_t);
        if (inc->time_until_elevation <= 0) {
            idx_to_del = it->index;
            node_iter_next(&it);
            simulation_handle_single_incantation(s, inc);
            list_pop(s->sim.incantations, idx_to_del);
            continue;
        }
        inc->time_until_elevation -= 1;
        node_iter_next(&it);
    }
}