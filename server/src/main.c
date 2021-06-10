/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** main
*/

#include "arg_parser.h"

int main(int ac, char **av)
{
    arguments_t args;

    if (parse_arguments(ac, av, &args))
        return 84;
    return 0;
}
