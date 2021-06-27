/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** get_from_option
*/

#include <criterion/criterion.h>

#include "arg_parser/arg_setter.h"
#include "arg_parser/arg_checker.h"

Test(arg_setter_get_from_option, success)
{
    cr_assert(arg_setter_get_from_option('p') == &arg_setter_port);
    cr_assert(arg_setter_get_from_option('x') == &arg_setter_width);
    cr_assert(arg_setter_get_from_option('y') == &arg_setter_height);
    cr_assert(arg_setter_get_from_option('n') == &arg_setter_name);
    cr_assert(arg_setter_get_from_option('f') == &arg_setter_frequency);
    cr_assert(arg_setter_get_from_option('c') == &arg_setter_clients_nb);
}

Test(arg_setter_get_from_option, unknown_options)
{
    cr_assert_null(arg_setter_get_from_option(0));
    cr_assert_null(arg_setter_get_from_option(1));
    cr_assert_null(arg_setter_get_from_option('.'));
    cr_assert_null(arg_setter_get_from_option('/'));
    cr_assert_null(arg_setter_get_from_option('&'));
    cr_assert_null(arg_setter_get_from_option('j'));
}