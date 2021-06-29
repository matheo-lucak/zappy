/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** gui_time_unit_request
*/

#include "server/request/handler.h"
#include "server/response/response.h"

void request_handler_gui_time_unit_request(server_t *s,
                                        client_t *c,
                                        __attribute__((unused))request_t *r)
{
    client_add_response(c, response_create(RESPONSE_SGT, s->freq));
}
