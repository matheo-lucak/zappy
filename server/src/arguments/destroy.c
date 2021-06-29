/*
** EPITECH PROJECT, 2021
** server
** File description:
** destroy
*/

#include <stdlib.h>

#include "arguments.h"

void arguments_destroy(arguments_t *args)
{
    if (!args)
        return;
    string_list_destroy(args->team_names);
    free(args);
}
