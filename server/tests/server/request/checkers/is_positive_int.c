/*
** EPITECH PROJECT, 2021
** server
** File description:
** is_positive_int
*/

#include <criterion/criterion.h>

#include "server/request/checker.h"

Test(request_arg_check_is_positive_int, success)
{
    cr_assert(request_arg_check_is_positive_int("0"));
    cr_assert(request_arg_check_is_positive_int("9"));
    cr_assert(request_arg_check_is_positive_int("120"));
    cr_assert(request_arg_check_is_positive_int("35412653"));
    cr_assert(request_arg_check_is_positive_int("00051254"));
}

Test(request_arg_check_is_positive_int, failure)
{
    cr_assert(!request_arg_check_is_positive_int(" 123"));
    cr_assert(!request_arg_check_is_positive_int("01a23"));
    cr_assert(!request_arg_check_is_positive_int("0123 "));
    cr_assert(!request_arg_check_is_positive_int("12a"));
    cr_assert(!request_arg_check_is_positive_int(NULL));
}