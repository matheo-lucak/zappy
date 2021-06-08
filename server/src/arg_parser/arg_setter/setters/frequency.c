/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** arg_setter_frequency
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "arg_parser/arg_checker.h"
#include "arg_parser/arg_setter.h"

static int arg_setter_frequency_error(void)
{
    fprintf(stderr, "-f option only accepts integer values"
                    " between 2 and 10000\n");
    return 1;
}

int arg_setter_frequency(arguments_t *arg)
{
    if (!optarg)
        return 1;
    if (arg_checker_positive_int(optarg))
        return arg_setter_frequency_error();
    arg->clients_nb = atoi(optarg);
    if (arg->clients_nb < 2 || arg->clients_nb > 10000)
        return arg_setter_frequency_error();
    return 0;
}