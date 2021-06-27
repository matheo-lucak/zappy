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
    client_t *c = client_create();
    char *input = strdup("Set deraumere");
    request_t *r = request_parse_from_input(input, CLIENT_DRONE);
    arguments_t args = arguments_default_values();
    server_t s;
    int status = server_start(&args, &s);

    client_to_drone(c, drone_create(0, 0, false));
    cr_assert(status == SERVER_SUCCESS);
    cr_assert(inventory_add_item(c->drone->inventory, RESOURCE_DERAUMERE, 1));
    cr_assert(!generic_list_find(s.sim.map->tiles[c->drone->y][c->drone->x]->items, RESOURCE_DERAUMERE, resource_type_t));
    request_handler_cmd_set(&s, c, r);
    cr_assert(generic_list_find(s.sim.map->tiles[c->drone->y][c->drone->x]->items, RESOURCE_DERAUMERE, resource_type_t));
    server_stop(&s);
}
