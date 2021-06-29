/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** handle
*/

#include <string.h>
#include <stdlib.h>

#include "server/server.h"
#include "server/request/request.h"
#include "server/response/response.h"

static void server_handle_single_request_parsing(server_t *s, client_t *c)
{
    char *input = NULL;
    bool was_split = false;
    char *split = NULL;
    char *del = NULL;

    if (!c->input_stock)
        return;
    split = c->input_stock;
    for (; (del = strchr(split, RQ_DELIMITER)); split = del + 1) {
        input = strndup(split, (void *)del - (void *)split);
        client_add_request(c, request_parse_from_input(input, c->type));
        free(input);
        was_split = true;
    }
    if (was_split) {
        split = strdup(split);
        free(c->input_stock);
        c->input_stock = split;
    }
}

void server_handle_request_parsing(server_t *s)
{
    client_t *c = NULL;

    list_foreach(node, s->clients) {
        c = NODE_PTR(node, client_t);
        server_handle_single_request_parsing(s, c);
    }
}
