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
    int status = server_start(args, &s);

    if (status != SERVER_SUCCESS) {
        server_stop(&s);
        return status;
    }
    status = server_run(&s);
    server_stop(&s);
    return status;
}