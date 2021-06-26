/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** cmd_set
*/

#include <criterion/criterion.h>
#include "server/request/handler.h"
#include "server/request/request.h"

Test(request_handler_cmd_take, simple_take)
{
    client_t *c = client_create();
    char *input = strdup("Take deraumere");
    request_t *r = request_parse_from_input(input, CLIENT_DRONE);
    arguments_t args = arguments_default_values();
    server_t s;
    int status = server_start(&args, &s);
    const item_slot_t *slot;

    cr_assert(status == SERVER_SUCCESS);
    cr_assert(tile_add_item(s.s.map->tiles[c->drone->y][c->drone->x], RESOURCE_DERAUMERE));
    cr_assert(inventory_get_item_info(c->drone->inventory, RESOURCE_DERAUMERE) == NULL);
    request_handler_cmd_take(&s, c, r);
    slot = inventory_get_item_info(c->drone->inventory, RESOURCE_DERAUMERE);
    cr_assert(slot != NULL);
    cr_assert(slot->type == RESOURCE_DERAUMERE);
    cr_assert(slot->quantity == 1);
    server_stop(&s);
}

Test(request_handler_cmd_take, several_same__take)
{
    client_t *c = client_create();
    char *input = strdup("Take deraumere");
    request_t *r = request_parse_from_input(input, CLIENT_DRONE);
    arguments_t args = arguments_default_values();
    server_t s;
    int status = server_start(&args, &s);
    const item_slot_t *slot;

    cr_assert(status == SERVER_SUCCESS);
    cr_assert(tile_add_item(s.s.map->tiles[c->drone->y][c->drone->x], RESOURCE_DERAUMERE));
    cr_assert(tile_add_item(s.s.map->tiles[c->drone->y][c->drone->x], RESOURCE_DERAUMERE));
    cr_assert(inventory_get_item_info(c->drone->inventory, RESOURCE_DERAUMERE) == NULL);
    request_handler_cmd_take(&s, c, r);
    request_handler_cmd_take(&s, c, r);
    slot = inventory_get_item_info(c->drone->inventory, RESOURCE_DERAUMERE);
    cr_assert(slot != NULL);
    cr_assert(slot->type == RESOURCE_DERAUMERE);
    cr_assert(slot->quantity == 2);
    server_stop(&s);
}
