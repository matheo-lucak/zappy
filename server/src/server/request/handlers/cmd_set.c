/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** cmd_set
*/

#include <string.h>
#include "server/request/handler.h"
#include "server/response/response.h"
#include "server/request/request.h"

void request_handler_cmd_set(server_t *s, client_t *c, request_t *r)
{
    bool is_ok = false;
    response_t *response = NULL;
    resource_type_t type = RESOURCE_FOOD;
    const node_t *node = list_get(r->arguments, 0);
    const resource_info_t *info = NULL;

    info = resource_get_info_from_name(node ? NODE_STR(node) : NULL);
    if (!info) {
        response = response_create(RESPONSE_KO);
        generic_list_push_back(c->pending_responses, response, response_t *);
        return;
    }
    type = info->type;
    is_ok = inventory_remove_item(c->drone->inventory, type, 1);
    if (is_ok) {
        is_ok = tile_add_item(s->s.map->tiles[c->drone->y][c->drone->x], type);
    }
    response = response_create(is_ok ? RESPONSE_OK : RESPONSE_KO);
    generic_list_push_back(c->pending_responses, response, response_t *);
}
