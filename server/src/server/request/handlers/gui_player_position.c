/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** gui_player_position
*/

#include <stdlib.h>

#include "server/request/handler.h"
#include "server/request/request.h"
#include "server/response/response.h"

void request_handler_gui_player_position(server_t *s, client_t *c, request_t *r)
{
    int targer_id = atoi(NODE_STR(list_begin(r->arguments)));
    drone_t *target = server_find_drone_from_id(s, targer_id);

    if (!target) {
        client_add_response(c, response_create(RESPONSE_KO));
    } else {
        client_add_response(c, response_create(RESPONSE_PPO,
            target->id,
            target->pos.x,
            target->pos.y,
            target->facing_direction
            ));
    }
}