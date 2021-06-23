/*
** EPITECH PROJECT, 2021
** server
** File description:
** checker
*/

#include "server/request/request.h"

static bool request_checker_arg_checker(request_t *request)
{
    size_t i = 0;
    char *arg = NULL;
    request_arg_checker_t checker = NULL;

    list_foreach(node, request->arguments) {
        arg = NODE_STR(node);
        checker = request->requirements->arg_checkers[i];
        if (!checker)
            break;
        if (!arg || !checker(arg))
            return false;
    }
    return true;
}

static bool request_checker_arg_number(request_t *request)
{
    if (request->requirements->arg_number == RQ_REQUIRE_NO_ARG)
        return true;
    return (size_t)request->requirements->arg_number
        == list_len(request->arguments);
}

static bool request_checker_client_type(client_t *client, request_t *request)
{
    if (request->requirements->client_type == RQ_REQUIRE_NO_CLIENT_TYPE)
        return true;
    return request->requirements->client_type & (int)client->type;
}

bool request_checker(client_t *client, request_t *request)
{
    if (!client || !request || !request->is_valid)
        return false;
    if (request_checker_client_type(client, request) == false)
        return false;
    if (request_checker_arg_number(request) == false)
        return false;
    if (request_checker_arg_checker(request) == false)
        return false;
    return true;
}