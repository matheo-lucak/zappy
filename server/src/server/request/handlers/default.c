/*
** EPITECH PROJECT, 2021
** server
** File description:
** default
*/

#include <string.h>
#include <stdlib.h>

#include "server/request/handler.h"
#include "server/request/request.h"
#include "server/response/response.h"

static void request_handler_default_gui(client_t *c)
{
    client_to_spectator(c);
    client_add_response(c, response_create(RESPONSE_GUI_MAGIC));
}

static drone_t *client_take_drone_control(server_t *s,
                                        map_t *map,
                                        team_t *team,
                                        client_t *c)
{
    vector2u_t pos = VEC2U(rand() % map->width, rand() % map->height);
    drone_t *d = team_new_active_drone(team, pos);

    if (!d)
        return NULL;
    client_to_drone(c, d);
    if (d->active) {
        server_add_notification(s, response_create(RESPONSE_PNW,
            d->id, d->pos.x, d->pos.y, d->facing_direction, d->elevation_lvl,
            team->name));
        map_add_drone(map, d);
    } else {
        server_add_notification(s, response_create(RESPONSE_EBO,
            d->id, d->pos.x, d->pos.y, d->facing_direction, d->elevation_lvl,
            team->name));
        d-> active = true;
    }
    return d;
}

static void request_handler_default_drone_join_team(server_t *s,
                                                    client_t *c,
                                                    team_t *team)
{
    drone_t *drone = client_take_drone_control(s, s->sim.map, team, c);

    if (drone) {
        client_add_response(c, response_create(RESPONSE_CLIENT_NUM,
                                            team->free_slots_nb));
        client_add_response(c, response_create(RESPONSE_XY,
                                            s->sim.map->width,
                                            s->sim.map->height));
    } else {
        client_add_response(c, response_create(RESPONSE_KO));
    }
}

static void request_handler_default_drone(server_t *s, client_t *c, char *name)
{
    team_t *team = NULL;

    list_foreach(it, s->sim.teams) {
        team = NODE_PTR(it, team_t);
        if (!strcmp(team->name, name)) {
            request_handler_default_drone_join_team(s, c, team);
            node_iter_end(&it);
            return;
        }
    }
    client_add_response(c, response_create(RESPONSE_KO));
}

void request_handler_default(server_t *s, client_t *c, request_t *r)
{
    if (!strcmp(r->name, RQ_MAGIC_GUI)) {
        request_handler_default_gui(c);
    } else {
        request_handler_default_drone(s, c, r->name);
    }
}
