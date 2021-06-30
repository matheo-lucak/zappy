/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** cmd_eject
*/

#include "server/server.h"
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

static void notify_ejection(server_t *s, drone_t *d)
{
    server_add_notification(s,
        response_create(RESPONSE_PEX, d->id));
}

static void eject_drone_from_tile(server_t *s, client_t *e_c, drone_t *d)
{
    client_t *eject_c = NULL;
    local_direction_t eject_dir = LCL_HERE;

    drone_eject(d, s->sim.map, e_c->drone->facing_direction);
    eject_c = get_client_from_drone(s, d);
    if (eject_c) {
        eject_dir = direction_get_eject_direction(
            d->facing_direction,
            e_c->drone->facing_direction
        );
        client_add_response(e_c, response_create(RESPONSE_EJECT, eject_dir));
        notify_ejection(s, d);
    }
}

void request_handler_cmd_eject(server_t *s,
                            client_t *c,
                            __attribute__((unused))request_t *r)
{
    drone_t *d = NULL;
    tile_t *tile = s->sim.map->tiles[c->drone->pos.y][c->drone->pos.x];

    if (list_empty(tile->drones)) {
        client_add_response(c, response_create(RESPONSE_KO));
        return;
    }
    list_foreach(node, tile->drones) {
        d = NODE_PTR(node, drone_t);
        if ((void *)d == (void *)c->drone)
            continue;
        eject_drone_from_tile(s, c, d);
    }
    client_add_response(c, response_create(RESPONSE_OK));
}
