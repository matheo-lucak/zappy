/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** cmd_fork
*/

#include "simulation/simulation.h"
#include "server/request/handler.h"
#include "server/response/response.h"

void request_handler_cmd_fork(server_t *s, client_t *c, request_t *r)
{
    drone_t *d = c->drone;
    team_t *team = simulation_find_team_from_drone(&s->sim, d);
    egg_t *egg = NULL;

    if (!d || !team) {
        client_add_response(c, response_create(RESPONSE_KO));
        return;
    }
    egg = egg_create(d->pos);
    team_add_egg(team, egg);
    client_add_response(c, response_create(RESPONSE_OK));
}
