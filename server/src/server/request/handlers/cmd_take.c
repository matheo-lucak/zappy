/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** cmd_take
*/

#include <string.h>
#include "server/request/handler.h"
#include "server/response/response.h"
#include "server/request/request.h"

static bool get_resource_type(string_list_t *arguments, resource_type_t *type)
{
    const node_t *node = arguments->get(arguments, 0);
    const char *str = NODE_PTR(node, char *);

    if (!strcmp(str, "food")) {
        *type = RESOURCE_FOOD;
        return true;
    }
    if (!strcmp(str, "linemate")) {
        *type = RESOURCE_LINEMATE;
        return true;
    }
    if (!strcmp(str, "deraumere")) {
        *type = RESOURCE_DERAUMERE;
        return true;
    }
    if (!strcmp(str, "sibur")) {
        *type = RESOURCE_SIBUR;
        return true;
    }
    if (!strcmp(str, "mendiane")) {
        *type = RESOURCE_MENDIANE;
        return true;
    }
    if (!strcmp(str, "phiras")) {
        *type = RESOURCE_PHIRAS;
        return true;
    }
    if (!strcmp(str, "thystame")) {
        *type = RESOURCE_THYSTAME;
        return true;
    }
    return false;
}

void request_handler_cmd_take(server_t *s, client_t *c, request_t *r)
{
    bool is_ok = false;
    response_t *response = NULL;
    resource_type_t type = RESOURCE_FOOD;

    if (!get_resource_type(r->arguments, &type))
        return;
    is_ok = tile_remove_item(s->s.map->tiles[c->drone->y][c->drone->x], type);
    if (is_ok) {
        is_ok = inventory_add_item(c->drone->inventory, type, 1);
    }
    response = response_create(is_ok ? RESPONSE_OK : RESPONSE_KO);
    generic_list_push_back(c->pending_responses, response, response_t *);
}
