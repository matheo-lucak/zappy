/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** parse
*/

#include <string.h>

#include "server/request/info.h"
#include "server/request/request.h"
#include "logger/logger.h"

static char *skip_to_next_arg(char **input)
{
    char *arg = NULL;

    if (!input || !*input)
        return NULL;
    arg = *input;
    *input = strpbrk(*input, RQ_SEPARATORS);
    if (*input) {
        **input = '\0';
        *input += 1;
    }
    return arg;
}

static int request_parse_arguments_from_input(request_t *request, char *input)
{
    char *arg = NULL;

    while (input && *input) {
        if (strchr(RQ_SEPARATORS, *input)) {
            server_log(LOG_SERVER_INVALID_REQUEST_ARG);
            return 1;
        }
        arg = skip_to_next_arg(&input);
        if (input && !*input) {
            server_log(LOG_SERVER_INVALID_REQUEST_ARG);
            return 1;
        }
        if (!arg) {
            server_log(LOG_SERVER_INVALID_REQUEST_ARG);
            return 1;
        }
        if (string_list_push_back(request->arguments, arg) == LIST_ERROR)
            return 1;
    }
    return 0;
}

static const request_info_t *request_parse_info_from_input(char **input,
                                                        char **req_name,
                                                        client_type_t type)
{
    char *cmd = NULL;

    if (!*input || strchr(RQ_SEPARATORS, **input))
        return NULL;
    cmd = skip_to_next_arg(input);
    if (*input && !**input) {
        server_log(LOG_SERVER_INVALID_REQUEST_ARG);
        return NULL;
    }
    if (!cmd) {
        server_log(LOG_SERVER_INVALID_REQUEST, "NULL");
        return NULL;
    }
    *req_name = strdup(cmd);
    if (type == CLIENT_UNKNOWN)
        return &default_request_info;
    return request_get_info_from_name(cmd);
}

request_t *request_parse_from_input(char *input, client_type_t type)
{
    char *r_name = NULL;
    const request_info_t *info = request_parse_info_from_input(
        &input, &r_name, type);
    request_t *request = NULL;

    request = request_create();
    if (!request)
        return NULL;
    request->name = r_name;
     if (info) {
        request->type = info->type;
        request->time_limit = info->time_limit;
        request->handler = info->handler;
        request->requirements = info->requirements;
        request->is_valid = true;
    } else
        request->is_valid = false;
    if (request_parse_arguments_from_input(request, input))
        request->is_valid = false;
    return request;
}
