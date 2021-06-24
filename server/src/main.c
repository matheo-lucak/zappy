/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** main
*/

#include <fcntl.h>
#include "arg_parser.h"
#include "server/server.h"

#include "server/response/response.h"

int main(int ac, char **av)
{
    response_t *res1 = response_create(RESPONSE_WELCOME);
    response_t *res2 = response_create(RESPONSE_CLIENT_NUM, 5);
    response_t *res3 = response_create(RESPONSE_XY, 15, 29);
    response_t *res4 = response_create(RESPONSE_OK);
    response_t *res5 = response_create(RESPONSE_KO);
    response_t *res6 = response_create(RESPONSE_DEAD);

    arguments_t args = arguments_default_values();

    if (parse_arguments(ac, av, &args))
        return SERVER_EXIT;
    return server_launch(&args);
}
