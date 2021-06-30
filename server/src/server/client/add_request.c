/*
** EPITECH PROJECT, 2021
** server
** File description:
** add_request
*/

#include <stdlib.h>
#include <my.h>

#include "logger/logger.h"
#include "server/request/request.h"
#include "server/client.h"

static char *get_concatenated_args(string_list_t *arguments)
{
    char *args = NULL;
    char *arg = NULL;

    list_foreach(node, arguments) {
        arg = NODE_STR(node);
        args = my_str_cat(args, arg, true, false);
        if (node->next)
            args = my_str_cat(args, " | ", true, false);
    }
    return args;
}

void client_add_request(client_t *c, request_t *request)
{
    char *args = NULL;

    if (!c || !request)
        return;
    args = get_concatenated_args(request->arguments);
    if (list_len(c->pending_requests) >= CLIENT_MAX_PENDING_REQUEST) {
        server_log(LOG_SERVER_IGNORED_VALID_REQUEST, request->name, c->id, args);
        free(args);
        return;
    }
    server_log(LOG_SERVER_ACCEPTED_VALID_REQUEST, request->name, c->id, args);
    free(args);
    ptr_list_push_back(c->pending_requests, request);
}
