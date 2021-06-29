/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** gui_tile_content
*/

#include <my.h>

#include "server/request/handler.h"
#include "server/request/request.h"
#include "server/response/response.h"
#include "simulation/map.h"

void request_handler_gui_tile_content(server_t *s, client_t *c, request_t *r)
{
    int x = my_get_nbr(NODE_STR(list_get(r->arguments, 0)));
    int y = my_get_nbr(NODE_STR(list_get(r->arguments, 1)));
    tile_t *tile = NULL;

    if (x < 0 || x >= (int)s->sim.map->width
        || y < 0 || y >= (int)s->sim.map->height) {
        client_add_response(c, response_create(RESPONSE_KO));
        return;
    }
    tile = s->sim.map->tiles[y][x];
    client_add_response(c, response_create(
        RESPONSE_BCT, x, y,
        tile_get_food_amount(tile), tile_get_linemate_amount(tile),
        tile_get_deraumere_amount(tile), tile_get_sibur_amount(tile),
        tile_get_mendiane_amount(tile), tile_get_phiras_amount(tile),
        tile_get_thystame_amount(tile)));
}
