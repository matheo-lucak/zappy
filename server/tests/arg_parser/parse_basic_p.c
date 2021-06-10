/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-poquard
** File description:
** parse_basic_p
*/

#include <criterion/criterion.h>

#include "arg_parser.h"

Test(parse_arguments, success_basic_p)
{
    char * av[] = {
        "./a.out",
        "-p",
        "4242"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args) == 0);
    cr_assert(args.port == 4242);
}

Test(parse_arguments, fail_p_no_arg)
{
    char * av[] = {
        "./a.out",
        "-p"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_p_bad_arg_1)
{
    char * av[] = {
        "./a.out",
        "-p",
        "-142"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_p_bad_arg_2)
{
    char * av[] = {
        "./a.out",
        "-p",
        "42sda42"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}