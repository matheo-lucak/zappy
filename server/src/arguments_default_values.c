/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** argument_default_values
*/

#include "arguments.h"

arguments_t arguments_default_values(void)
{
    arguments_t args = {0};

    args.port = 3;
    args.clients_nb = 3;
    args.width = 10;
    args.height = 10;
    args.freq = 100;
    return args;
}
