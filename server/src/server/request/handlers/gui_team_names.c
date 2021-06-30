/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** gui_team_names
*/

#include "server/response/response.h"
#include "server/request/handler.h"

void request_handler_gui_team_names(server_t *s,
                                    client_t *c, 
                                    __attribute__((unused))request_t *r)
{
    team_t *team = NULL;

    if (list_empty(s->sim.teams)) {
        client_add_response(c, response_create(RESPONSE_KO));
        return;
    }
    list_foreach(it, s->sim.teams) {
        team = NODE_PTR(it, team_t);
        client_add_response(c, response_create(RESPONSE_TNA, team->name));
    }
}
