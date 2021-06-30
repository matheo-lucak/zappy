/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** cmd_fork
*/

#include "simulation/simulation.h"
#include "server/request/handler.h"
#include "server/response/response.h"

static void server_notification_egg_laid(server_t *s,
                                        client_t *c,
                                        egg_t *e)
{
    server_add_notification(s, response_create(RESPONSE_ENW,
        e->id,
        c->drone->id,
        e->pos.x,
        e->pos.y
    ));
}

void request_handler_cmd_fork(server_t *s,
                            client_t *c,
                            __attribute__((unused))request_t *r)
{
    drone_t *d = c->drone;
    team_t *team = simulation_find_team_from_drone(&s->sim, d);
    egg_t *egg = NULL;

    if (!d || !team) {
        client_add_response(c, response_create(RESPONSE_KO));
        return;
    }
    egg = egg_create(d->pos);
    if (!egg) {
        client_add_response(c, response_create(RESPONSE_KO));
    } else {
        team_add_egg(team, egg);
        client_add_response(c, response_create(RESPONSE_OK));
        server_notification_egg_laid(s, c, egg);
    }
}
