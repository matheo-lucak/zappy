/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** parse
*/

#include <criterion/criterion.h>

#include "arg_parser.h"

Test(parse_arguments, success_no_arg)
{
    char * av[] = {
        "./a.out"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args) == 0);
}

Test(parse_arguments, success_two_args_1)
{
    char * av[] = {
        "./a.out",
        "-c", "1542",
        "-p", "4242"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args) == 0);
    cr_assert(args.clients_nb == 1542);
    cr_assert(args.port == 4242);
}

Test(parse_arguments, success_two_args_2)
{
    char * av[] = {
        "./a.out",
        "-x", "15",
        "-y", "18"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args) == 0);
    cr_assert(args.width == 15);
    cr_assert(args.height == 18);
}

Test(parse_arguments, success_many_args_1)
{
    char * av[] = {
        "./a.out",
        "-x", "15",
        "-p", "6454",
        "-y", "18",
        "-c", "1542",
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args) == 0);
    cr_assert(args.port == 6454);
    cr_assert(args.clients_nb == 1542);
    cr_assert(args.width == 15);
    cr_assert(args.height == 18);
}

Test(parse_arguments, success_many_args_2)
{
    char * av[] = {
        "./a.out",
        "-y", "18",
        "-n", "Team name 1",
        "-x", "15",
        "-p", "6454",
        "-n", "Team name 2", "Team name 3"
    };
    int ac = sizeof(av) / sizeof(*av);
    arguments_t args = {0};

    cr_assert(parse_arguments(ac, av, &args) == 0);
    cr_assert(string_list_contains(args.team_names, "Team name 1"));
    cr_assert(string_list_contains(args.team_names, "Team name 2"));
    cr_assert(string_list_contains(args.team_names, "Team name 3"));
    cr_assert(args.width == 15);
    cr_assert(args.height == 18);
    cr_assert(args.port == 6454);
    cr_assert(args.team_names);
}
