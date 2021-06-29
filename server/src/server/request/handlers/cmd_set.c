/*
** EPITECH PROJECT, 2021
** Zappy
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
    resource_type_t type = RESOURCE_FOOD;
    const node_t *node = list_get(r->arguments, 0);
    const resource_info_t *info = NULL;
    tile_t *tile = NULL;

    info = resource_get_info_from_name(node ? NODE_STR(node) : NULL);
    if (!info) {
        client_add_response(c, response_create(RESPONSE_KO));
        return;
    }
    type = info->type;
    is_ok = inventory_remove_item(c->drone->inventory, type, 1);
    if (is_ok) {
        tile = s->sim.map->tiles[c->drone->pos.y][c->drone->pos.x];
        is_ok = tile_add_item(tile, type);
    }
    client_add_response(c, response_create(is_ok ? RESPONSE_OK : RESPONSE_KO));
}
