/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** launch
*/

#include "server/server.h"
#include "arguments.h"

int server_launch(const arguments_t *args)
{
    server_t s;
    int error = server_start(args, &s);

    if (error != SERVER_SUCCESS)
        return error;
    error = server_run(&s);
    server_stop(&s);
    return error;
}