/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** arg_setter_name
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "arg_parser/arg_checker.h"
#include "arg_parser/arg_setter.h"

static int arg_setter_name_error(void)
{
    fprintf(stderr, "-n option only accepts unique team names\n");
    return 1;
}

int arg_setter_name(arguments_t *arg)
{
    if (!optarg)
        return 1;
    arg->team_names = NULL;
    return 0;
}