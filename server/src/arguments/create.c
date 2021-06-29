/*
** EPITECH PROJECT, 2021
** server
** File description:
** create
*/

#include <stdlib.h>

#include "arguments.h"

arguments_t *arguments_create(void)
{
    arguments_t *args = malloc(sizeof(arguments_t));

    if (!args)
        return NULL;
    arguments_set_default_values(args);
    args->team_names = string_list_create();
    if (!args->team_names) {
        arguments_destroy(args);
        return NULL;
    }
    return args;
}
