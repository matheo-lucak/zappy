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
    arguments_t args = arguments_default_values();

    if (parse_arguments(ac, av, &args))
        return SERVER_EXIT;
    return server_launch(&args);
}
