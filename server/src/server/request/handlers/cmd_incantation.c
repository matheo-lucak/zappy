/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** cmd_incantation
*/

#include "server/request/handler.h"
#include "simulation/incantation.h"
#include "server/response/response.h"

void request_handler_cmd_incantation(server_t *s, client_t *c, request_t *r)
{
    client_t *client = NULL;
    tile_t *tile = s->sim.map->tiles[c->drone->pos.y][c->drone->pos.x];
    incantation_t *inc = incantation_create(c->drone, tile);

    if (!inc || !incantation_check_requirements(inc)) {
        client_add_response(c, response_create(RESPONSE_KO));
        return;
    }
    client_block(c);
    list_foreach(it, tile->drones) {
        client = server_find_client_from_drone(s, NODE_PTR(it, drone_t));
        if (client)
            client_add_response(client, response_create(RESPONSE_INCANTATION));
    }
    ptr_list_push_back(s->sim.incantations, inc);
}
