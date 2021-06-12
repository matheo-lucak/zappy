/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** launch
*/

#include "arguments.h"

int launch_server(const arguments_t *args)
{
    server_t s;
    int error = 0;

    if (start_server(args, &s))
        return 1;
    stop_server(&s);
    return error;
}