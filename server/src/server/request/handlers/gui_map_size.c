/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** gui_map_size
*/

#include "server/request/handler.h"
#include "server/response/response.h"

void request_handler_gui_map_size(server_t *s,
                                client_t *c,
                                __attribute__((unused)) request_t *r)
{
    client_add_response(c, response_create(RESPONSE_MSZ,
        s->sim.map->width, s->sim.map->height)
    );
}
