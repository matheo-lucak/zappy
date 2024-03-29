/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** arg_setter_name
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "arg_parser/arg_checker.h"
#include "arg_parser/arg_setter.h"

#include "server/request/request.h"

static int arg_setter_unique_name_error(void)
{
    fprintf(stderr, "-n option only accepts unique team names\n");
    return 1;
}

static int arg_setter_magic_gui_name_error(void)
{
    fprintf(stderr, "-n option must not match \"%s\"\n", RQ_MAGIC_GUI);
    return 1;
}

int arg_setter_name_set_all_names(arguments_t *arg, int ac, char **av)
{
    int index = optind - 1;

    for (; index < ac; index++) {
        if (!av[index] || av[index][0] == '-')
            break;
        if (!strcmp(av[index], RQ_MAGIC_GUI))
            return arg_setter_magic_gui_name_error();
        if (string_list_contains(arg->team_names, av[index]))
            return arg_setter_unique_name_error();
        string_list_push_back(arg->team_names, av[index]);
    }
    optind = index - 1;
    return 0;
}

int arg_setter_name(arguments_t *arg, ...)
{
    va_list ap;
    int ac = 0;
    char **av = NULL;

    va_start(ap, arg);
    ac = va_arg(ap, int);
    av = va_arg(ap, char **);
    va_end(ap);
    if (!arg->team_names)
        arg->team_names = string_list_create();
    if (!ac || !av || !arg->team_names)
        return 1;
    return arg_setter_name_set_all_names(arg, ac, av);
}