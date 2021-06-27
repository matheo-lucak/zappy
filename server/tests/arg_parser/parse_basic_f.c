/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-foquard
** File description:
** parse_basic_f
*/

#include <criterion/criterion.h>

#include "arg_parser.h"

Test(parse_arguments, success_basic_f_1)
{
    char * av[] = {
        "./a.out",
        "-f",
        "4242"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args) == 0);
    cr_assert(args.freq == 4242);
}

Test(parse_arguments, success_basic_f_minimum_value)
{
    char * av[] = {
        "./a.out",
        "-f",
        "2"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args) == 0);
    cr_assert(args.freq == 2);
}

Test(parse_arguments, fail_basic_f_below_minimum_value)
{
    char * av[] = {
        "./a.out",
        "-f",
        "1"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, success_basic_f_maximum_value)
{
    char * av[] = {
        "./a.out",
        "-f",
        "10000"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args) == 0);
    cr_assert(args.freq == 10000);
}

Test(parse_arguments, fail_basic_f_above_maximum_value)
{
    char * av[] = {
        "./a.out",
        "-f",
        "10001"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_f_no_arg)
{
    char * av[] = {
        "./a.out",
        "-f"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_f_bad_arg_1)
{
    char * av[] = {
        "./a.out",
        "-f",
        "-142"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_f_bad_arg_2)
{
    char * av[] = {
        "./a.out",
        "-f",
        "42sda42"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_f_bad_arg_3)
{
    char * av[] = {
        "./a.out",
        "-f",
        "0"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_f_bad_arg_4)
{
    char * av[] = {
        "./a.out",
        "-f",
        ""
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}