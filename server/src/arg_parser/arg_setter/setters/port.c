/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** arg_setter_port
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "arg_parser/arg_checker.h"
#include "arg_parser/arg_setter.h"

static int arg_setter_port_error(void)
{
    fprintf(stderr, "-p option only accepts valid ports\n");
    return 1;
}

int arg_setter_port(arguments_t *arg, ...)
{
    if (!optarg)
        return 1;
    if (arg_checker_positive_int(optarg))
        return arg_setter_port_error();
    arg->port = atoi(optarg);
    return 0;
}
