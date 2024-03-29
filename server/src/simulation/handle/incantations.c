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

static void server_notification_end_incantation(server_t *s,
                                                incantation_t *i,
                                                bool success)
{
    server_add_notification(s, response_create(RESPONSE_PIE,
        i->pos.x,
        i->pos.y,
        success
    ));
}

static void simulation_handle_inc_fail(server_t *s, client_t *c,
                                            incantation_t *inc)
{
    server_notification_end_incantation(s, inc, false);
    list_foreach(it, inc->tile->drones) {
        c = server_find_client_from_drone(s, NODE_PTR(it, drone_t));
        if (c)
            client_add_response(c, response_create(RESPONSE_KO));
    }
}

static void simulation_handle_inc_success(server_t *s, client_t *c,
                                                incantation_t *inc)
{
    client_unblock(c);
    incantation_elevate(inc);
    server_notification_end_incantation(s, inc, true);
    list_foreach(it, inc->tile->drones) {
        c = server_find_client_from_drone(s, NODE_PTR(it, drone_t));
        if (c) {
            client_add_response(c,
                response_create(RESPONSE_ELEVATION, inc->elevation_lvl + 1));
        }
    }
}

static void simulation_handle_single_incantation(server_t *s,
                                            incantation_t *inc)
{
    client_t *client = server_find_client_from_drone(s, inc->owner);

    if (!client || !incantation_check_requirements(inc)) {
        simulation_handle_inc_fail(s, client, inc);
        return;
    }
    simulation_handle_inc_success(s, client, inc);
    simulation_check_end_of_game(s);
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