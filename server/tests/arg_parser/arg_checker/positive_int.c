/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** positive_int
*/

#include <criterion/criterion.h>

#include "arg_parser/arg_checker.h"

Test(arg_checker_positive_int, success)
{
    cr_assert(arg_checker_positive_int("0") == 0);
    cr_assert(arg_checker_positive_int("1") == 0);
    cr_assert(arg_checker_positive_int("42") == 0);
    cr_assert(arg_checker_positive_int("541872") == 0);
}

Test(arg_checker_positive_int, null)
{
    cr_assert(arg_checker_positive_int(NULL) != 0);
}

Test(arg_checker_positive_int, negative)
{
    cr_assert(arg_checker_positive_int("-1") != 0);
    cr_assert(arg_checker_positive_int("-42") != 0);
    cr_assert(arg_checker_positive_int("-541872") != 0);
}

Test(arg_checker_positive_int, non_digit)
{
    cr_assert(arg_checker_positive_int("abc") != 0);
    cr_assert(arg_checker_positive_int("ScvSF") != 0);
    cr_assert(arg_checker_positive_int("?.") != 0);
}

Test(arg_checker_positive_int, mix_digit_non_digit)
{
    cr_assert(arg_checker_positive_int("12abc") != 0);
    cr_assert(arg_checker_positive_int("abc12") != 0);
    cr_assert(arg_checker_positive_int("654/") != 0);
    cr_assert(arg_checker_positive_int("654!142") != 0);
    cr_assert(arg_checker_positive_int("0.") != 0);
}