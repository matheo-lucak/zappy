/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** cmd_eject
*/

#include "server/request/handler.h"
#include "server/response/response.h"
#include "simulation/drone.h"

static int client_drone_finder(client_t *client, drone_t *drone)
{
    return (void *)client->drone != (void *)drone;
}

static client_t *get_client_from_drone(server_t *s, drone_t *drone)
{
    const node_t *node = ptr_list_find_cmp(s->clients,
                                            drone,
                                            &client_drone_finder);

    if (!node)
        return NULL;
    return NODE_PTR(node, client_t);
}

static void eject_drone_from_tile(server_t *s, client_t *ejector, drone_t *d)
{
    client_t *eject_c = NULL;
    local_direction_t eject_index = LCL_UNKNOWN;
    response_t *response = NULL;

    drone_eject(d, s->sim.map, ejector->drone->facing_direction);
    eject_c = get_client_from_drone(s, d);
    if (eject_c) {
        eject_index = direction_get_eject_direction(
            d->facing_direction,
            ejector->drone->facing_direction
        );
        response = response_create(RESPONSE_EJECT, eject_index);
        client_add_response(ejector, response);
    }
}

void request_handler_cmd_eject(server_t *s, client_t *c, request_t *r)
{
    drone_t *d = NULL;
    if (list_empty(s->sim.map->tiles[c->drone->y][c->drone->x]->drones)) {
        client_add_response(c, response_create(RESPONSE_KO));
        return;
    }
    list_foreach(node, s->sim.map->tiles[c->drone->y][c->drone->x]->drones) {
        d = NODE_PTR(node, drone_t);
        if ((void *)d == (void *)c->drone)
            continue;
        eject_drone_from_tile(s, c, d);
    }
    client_add_response(c, response_create(RESPONSE_OK));
}
