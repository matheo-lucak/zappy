/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** arg_setter_height
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "arg_parser/arg_checker.h"
#include "arg_parser/arg_setter.h"

static int arg_setter_height_error(void)
{
    fprintf(stderr, "-y option only accepts integer values"
                    " between 10 and 30\n");
    return 1;
}

int arg_setter_height(arguments_t *arg, ...)
{
    if (!optarg)
        return 1;
    if (arg_checker_positive_int(optarg))
        return arg_setter_height_error();
    arg->height = atoi(optarg);
    if (arg->height < 10 || arg->height > 30)
        return arg_setter_height_error();
    return 0;
}