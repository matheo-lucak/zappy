/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** gui_map_content
*/

#include "server/request/handler.h"
#include "server/response/response.h"

void request_handler_gui_map_content(server_t *s,
                                    client_t *c,
                                    __attribute__((unused))request_t *r)
{
    tile_t *tile = NULL;

    for (unsigned int y = 0; y < s->sim.map->height; y++) {
        for (unsigned int x = 0; x < s->sim.map->width; x++) {
            tile = s->sim.map->tiles[y][x];
            client_add_response(c, response_create(
                RESPONSE_MCT, x, y,
                tile_get_food_amount(tile), tile_get_linemate_amount(tile),
                tile_get_deraumere_amount(tile), tile_get_sibur_amount(tile),
                tile_get_mendiane_amount(tile), tile_get_phiras_amount(tile),
                tile_get_thystame_amount(tile)));
        }
    }
}
