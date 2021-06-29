/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** main
*/

#include "arg_parser.h"
#include "server/server.h"

int main(int ac, char **av)
{
    arguments_t *args = arguments_create();
    int status = 0;

    if (parse_arguments(ac, av, args))
        return SERVER_EXIT;
    status = server_launch(args);
    arguments_destroy(args);
    return status;
}
