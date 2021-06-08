/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-xoquard
** File description:
** parse_basic_x
*/

#include <criterion/criterion.h>

#include "arg_parser.h"

Test(parse_arguments, success_basic_x_1)
{
    char * av[] = {
        "./a.out",
        "-x",
        "10"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args) == 0);
    cr_assert(args.width == 10);
}

Test(parse_arguments, success_basic_x_2)
{
    char * av[] = {
        "./a.out",
        "-x",
        "15"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args) == 0);
    cr_assert(args.width == 15);
}

Test(parse_arguments, success_basic_x_3)
{
    char * av[] = {
        "./a.out",
        "-x",
        "30"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args) == 0);
    cr_assert(args.width == 30);
}

Test(parse_arguments, fail_x_no_arg)
{
    char * av[] = {
        "./a.out",
        "-x"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_x_bad_arg_1)
{
    char * av[] = {
        "./a.out",
        "-x",
        "-142"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_x_bad_arg_2)
{
    char * av[] = {
        "./a.out",
        "-x",
        "42sda42"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_x_bad_arg_3)
{
    char * av[] = {
        "./a.out",
        "-x",
        "0"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_x_bad_arg_4)
{
    char * av[] = {
        "./a.out",
        "-x",
        "9"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_x_bad_arg_5)
{
    char * av[] = {
        "./a.out",
        "-x",
        "31"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_x_bad_arg_6)
{
    char * av[] = {
        "./a.out",
        "-x",
        "5122"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}