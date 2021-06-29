/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** argument_default_values
*/

#include "arguments.h"

void arguments_set_default_values(arguments_t *args)
{
    if (!args)
        return;
    args->port = 0;
    args->clients_nb = 3;
    args->width = 10;
    args->height = 10;
    args->freq = 100;
}
