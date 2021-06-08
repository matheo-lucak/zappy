/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-poquard
** File description:
** parse_basic_p
*/

#include <criterion/criterion.h>

#include "arg_parser.h"

Test(parse_arguments, success_basic_y_1)
{
    char * av[] = {
        "./a.out",
        "-y",
        "10"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args) == 0);
    cr_assert(args.height == 10);
}

Test(parse_arguments, success_basic_y_2)
{
    char * av[] = {
        "./a.out",
        "-y",
        "15"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args) == 0);
    cr_assert(args.height == 15);
}

Test(parse_arguments, success_basic_y_3)
{
    char * av[] = {
        "./a.out",
        "-y",
        "30"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args) == 0);
    cr_assert(args.height == 30);
}

Test(parse_arguments, fail_y_no_arg)
{
    char * av[] = {
        "./a.out",
        "-y"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_y_bad_arg_1)
{
    char * av[] = {
        "./a.out",
        "-y",
        "-142"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_y_bad_arg_2)
{
    char * av[] = {
        "./a.out",
        "-y",
        "42sda42"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_y_bad_arg_3)
{
    char * av[] = {
        "./a.out",
        "-y",
        "0"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_y_bad_arg_4)
{
    char * av[] = {
        "./a.out",
        "-y",
        "9"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_y_bad_arg_5)
{
    char * av[] = {
        "./a.out",
        "-y",
        "31"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_y_bad_arg_6)
{
    char * av[] = {
        "./a.out",
        "-y",
        "5122"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}