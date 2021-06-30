/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** cmd_incantation
*/

#include "server/request/handler.h"
#include "simulation/incantation.h"
#include "server/response/response.h"

static void server_notification_start_incantation(server_t *s,
                                                    client_t *c,
                                                    incantation_t *i)
{
    server_add_notification(s, response_create(RESPONSE_PIC,
        i->pos.x,
        i->pos.y,
        i->elevation_lvl,
        c->drone->id,
        i->requirements[RESOURCE_LINEMATE],
        i->requirements[RESOURCE_DERAUMERE],
        i->requirements[RESOURCE_SIBUR],
        i->requirements[RESOURCE_MENDIANE],
        i->requirements[RESOURCE_PHIRAS],
        i->requirements[RESOURCE_THYSTAME]
    ));
}

void request_handler_cmd_incantation(server_t *s,
                                    client_t *c,
                                    __attribute__((unused))request_t *r)
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
    server_notification_start_incantation(s, c, inc);
    ptr_list_push_back(s->sim.incantations, inc);
}
