/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** cmd_set
*/

#include <criterion/criterion.h>
#include "server/request/handler.h"
#include "server/request/request.h"

Test(request_handler_cmd_set, simple_set)
{
    arguments_t args = arguments_default_values();
    server_t s;
    int status = server_start(&args, &s);
    client_t *c = client_create();
    char *input = strdup("Set deraumere");
    request_t *r = request_parse_from_input(input, CLIENT_DRONE);
    tile_t *tile = NULL;

    client_to_drone(c, drone_create(VEC2U(0, 0), false));
    tile = s.sim.map->tiles[c->drone->pos.y][c->drone->pos.x];
    cr_assert(status == SERVER_SUCCESS);
    cr_assert(inventory_add_item(c->drone->inventory, RESOURCE_DERAUMERE, 1));
    cr_assert(!generic_list_find(tile->items,
                        RESOURCE_DERAUMERE, resource_type_t));
    request_handler_cmd_set(&s, c, r);
    cr_assert(generic_list_find(tile->items,
                        RESOURCE_DERAUMERE, resource_type_t));
    server_stop(&s);
}
