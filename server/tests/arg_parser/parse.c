/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
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