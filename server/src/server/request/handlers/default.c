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
    // TO IMPLEMENT: Send response
 }

static void request_handler_default_drone_join_team(server_t *s, client_t *c,
                                                                team_t *team)
{
    int x = rand() % s->sim.map->width;
    int y = rand() % s->sim.map->height;
    drone_t *drone = team_new_active_drone(team, x, y);

    if (drone) {
        client_to_drone(c, drone);
        client_add_response(c,
            response_create(RESPONSE_CLIENT_NUM, team->free_slots_nb));
        client_add_response(c,
            response_create(RESPONSE_XY, s->sim.map->width, s->sim.map->height));
        tile_add_drone(s->sim.map->tiles[y][x], drone);
    } else {
        client_add_response(c, response_create(RESPONSE_KO));
    }
}

static void request_handler_default_drone(server_t *s, client_t *c, char *name)
{
    team_t *team = NULL;
    drone_t *drone = NULL;

    list_foreach(it, s->sim.teams) {
        team = NODE_PTR(it, team_t);
        if (!strcmp(team->name, name)) {
            request_handler_default_drone_join_team(s, c, team);
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
