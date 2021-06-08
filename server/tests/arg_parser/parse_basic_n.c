/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-poquard
** File description:
** parse_basic_n
*/

#include <criterion/criterion.h>

#include "arg_parser.h"

//Test(parse_arguments, success_basic_n)
//{
//    int ac = sizeof(av) / sizeof(*av);

//    char * av[] = {
//        "./a.out",
//        "-p",
//        "4242"
//    };
//    arguments_t args = {0};
//
//    cr_assert(parse_arguments(ac, av, &args) == 0);
//    cr_assert(args.port == 4242);
//}
//
//Test(parse_arguments, fail_n_no_arg)
//{
//    int ac = sizeof(av) / sizeof(*av);

//    char * av[] = {
//        "./a.out",
//        "-p"
//    };
//    arguments_t args = {0};
//
//    cr_assert(parse_arguments(ac, av, &args));
//}
//
//Test(parse_arguments, fail_n_bad_arg_1)
//{
//    int ac = sizeof(av) / sizeof(*av);

//    char * av[] = {
//        "./a.out",
//        "-p",
//        "-142"
//    };
//    arguments_t args = {0};
//
//    cr_assert(parse_arguments(ac, av, &args));
//}
//
//Test(parse_arguments, fail_n_bad_arg_2)
//{
//    int ac = sizeof(av) / sizeof(*av);

//    char * av[] = {
//        "./a.out",
//        "-p",
//        "42sda42"
//    };
//    arguments_t args = {0};
//
//    cr_assert(parse_arguments(ac, av, &args));
//}