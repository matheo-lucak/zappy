/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** arg_setter_width
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "arg_parser/arg_checker.h"
#include "arg_parser/arg_setter.h"

static int arg_setter_width_error(void)
{
    fprintf(stderr, "-x option only accepts integer values"
                    " between 10 and 30\n");
    return 1;
}

int arg_setter_width(arguments_t *arg)
{
    if (!optarg)
        return 1;
    if (arg_checker_positive_int(optarg))
        return arg_setter_width_error();
    arg->width = atoi(optarg);
    if (arg->width < 10 || arg->width > 30)
        return arg_setter_width_error();
    return 0;
}
