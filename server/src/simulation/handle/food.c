/*
** EPITECH PROJECT, 2021
** server
** File description:
** food
*/

#include "logger/logger.h"

#include "server/server.h"
#include "server/response/response.h"
#include "simulation/simulation.h"

static void server_notification_death(server_t *s,
                                    drone_t *d)
{
    if (d->active) {
        server_add_notification(s, response_create(RESPONSE_PDI, d->id));
    } else {
        server_add_notification(s, response_create(RESPONSE_EDI, d->id));
    }
}
static void simulation_handle_food_eat(server_t *s, drone_t *drone)
{
    client_t *client = NULL;

    if (drone_eat(drone))
        return;
    server_notification_death(s, drone);
    server_log(LOG_SIMULATION_DRONE_DIED, drone->pos.x, drone->pos.y);
    client = drone->active ? server_find_client_from_drone(s, drone) : NULL;
    if (client) {
        client->alive = false;
        client->drone = NULL;
        client->type = CLIENT_UNKNOWN;
        client_add_response(client, response_create(RESPONSE_DEAD));
    }
    simulation_remove_drone(&s->sim, drone);
}

void simulation_handle_food(server_t *s)
{
    team_t *team = NULL;
    drone_t *drone = NULL;
    node_iterator_t *drone_it = NULL;

    list_foreach(team_it, s->sim.teams) {
        team = NODE_PTR(team_it, team_t);
        for (drone_it = list_iter_begin(team->drones); drone_it;) {
            drone = NODE_PTR(drone_it, drone_t);
            node_iter_next(&drone_it);
            simulation_handle_food_eat(s, drone);
        }
    }
}