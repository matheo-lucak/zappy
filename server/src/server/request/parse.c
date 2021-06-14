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

static const request_info_t *request_parse_info_from_input(char **input)
{
    const request_info_t *info = NULL;
    char *cmd = NULL;

    if (!*input || strchr(RQ_SEPARATORS, **input))
        return NULL;
    cmd = skip_to_next_arg(input);
    if (*input && !**input) {
        server_log(LOG_SERVER_INVALID_REQUEST_ARG);
        return NULL;
    }
    info = request_get_info_from_name(cmd);
    if (!info) {
        server_log(LOG_SERVER_INVALID_REQUEST, cmd ? cmd : "");
        return NULL;
    }
    return info;
}

request_t *request_parse_from_input(char *input)
{
    const request_info_t *info = request_parse_info_from_input(&input);
    request_t *request = NULL;

    if (!info)
        return NULL;
    request = request_create();
    if (!request)
        return NULL;
    request->type = info->type;
    request->time_limit = info->time_limit;
    if (request_parse_arguments_from_input(request, input)) {
        request_destroy(request);
        return NULL;
    }
    return request;
}
