/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** parse
*/

#include <unistd.h>

#include "arg_parser/arg_options.h"
#include "arg_parser/arg_setter.h"
#include "arg_parser.h"

static int parse_non_positional_args(int ac, char * const * av,
                                            arguments_t * args)
{
    int error = 0;
    int option = 0;
    arg_setter_t setter = NULL;

    do {
        option = getopt_long(ac, av, short_options, long_options, NULL);
        if (option == -1)
            break;
        setter = arg_setter_get_from_option(option);
        if (!setter)
            return -1;
        error = setter(args, ac, av);
    } while (error == 0);
    return error;
}

int parse_arguments(int ac, char * const * av, arguments_t * args)
{
    return parse_non_positional_args(ac, av, args);
}
