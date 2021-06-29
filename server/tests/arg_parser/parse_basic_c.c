/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** parse_basic_c
*/

#include <criterion/criterion.h>

#include "arg_parser.h"

Test(parse_arguments, success_basic_c_1)
{
    char * av[] = {
        "./a.out",
        "-c",
        "4242"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args) == 0);
    cr_assert(args.clients_nb == 4242);
}

Test(parse_arguments, success_basic_c_2)
{
    char * av[] = {
        "./a.out",
        "-c",
        "1"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args) == 0);
    cr_assert(args.clients_nb == 1);
}

Test(parse_arguments, fail_c_no_arg)
{
    char * av[] = {
        "./a.out",
        "-c"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_c_bad_arg_1)
{
    char * av[] = {
        "./a.out",
        "-c",
        "-142"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_c_bad_arg_2)
{
    char * av[] = {
        "./a.out",
        "-c",
        "42sda42"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_c_bad_arg_3)
{
    char * av[] = {
        "./a.out",
        "-c",
        "0"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_c_bad_arg_4)
{
    char * av[] = {
        "./a.out",
        "-c",
        ""
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}