/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** cmd_connect_nbr
*/

#include "server/request/handler.h"
#include "server/response/response.h"
#include "simulation/simulation.h"

void request_handler_cmd_connect_nbr(server_t *s, client_t *c, request_t *r)
{
    drone_t *drone = c->drone;
    team_t *team =  simulation_find_team_from_drone(&s->sim, drone);

    if (!team) {
        client_add_response(c, response_create(RESPONSE_KO));
        return;
    }
    client_add_response(c,
        response_create(RESPONSE_CLIENT_NUM, team->free_slots_nb));
}