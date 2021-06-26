/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** gui_map_size
*/

#include "server/request/handler.h"
#include "server/response/response.h"

void request_handler_gui_map_size(server_t *s, client_t *c, request_t *r)
{
    response_t *response = NULL;

    response = response_create(RESPONSE_MSZ, s->s.map->width, s->s.map->height);
    ptr_list_push_back(c->pending_responses, response);
}
