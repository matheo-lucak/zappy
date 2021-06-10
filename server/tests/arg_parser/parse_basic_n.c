/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-poquard
** File description:
** parse_basic_n
*/

#include <criterion/criterion.h>

#include "arg_parser.h"

Test(parse_arguments, success_basic_n_one_name)
{
    char * av[] = {
        "./a.out",
        "-n",
        "Team name 1"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args) == 0);
    cr_assert(args.team_names);
    cr_assert(string_list_contains(args.team_names, "Team name 1"));
}

Test(parse_arguments, success_basic_n_two_name)
{
    char * av[] = {
        "./a.out",
        "-n",
        "Team name 1",
        "Team name 2"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args) == 0);
    cr_assert(args.team_names);
    cr_assert(string_list_contains(args.team_names, "Team name 1"));
    cr_assert(string_list_contains(args.team_names, "Team name 2"));
    cr_assert(list_len(args.team_names));
}

Test(parse_arguments, fail_n_no_arg)
{
    char * av[] = {
        "./a.out",
        "-n"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}

Test(parse_arguments, fail_n_duplicated_names)
{
    char * av[] = {
        "./a.out",
        "-n",
        "Team name 1",
        "Team name 2",
        "Team name 1",
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args));
}