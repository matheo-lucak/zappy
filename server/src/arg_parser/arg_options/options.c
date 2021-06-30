/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** arg_options
*/

#include <stddef.h>

#include "arg_parser/arg_options.h"

const char *short_options = "p:x:y:n:c:f:";

const struct option long_options[] = {
    {.name = "port",        .has_arg = 0, .flag = NULL, .val = 'p'},
    {.name = "width",       .has_arg = 0, .flag = NULL, .val = 'x'},
    {.name = "height",      .has_arg = 0, .flag = NULL, .val = 'y'},
    {.name = "name",        .has_arg = 0, .flag = NULL, .val = 'n'},
    {.name = "clientsNb",   .has_arg = 0, .flag = NULL, .val = 'c'},
    {.name = "frequency",   .has_arg = 0, .flag = NULL, .val = 'f'},
    {.name = NULL,          .has_arg = 0, .flag = NULL, .val = 0}
};