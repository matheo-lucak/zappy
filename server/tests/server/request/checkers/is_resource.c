/*
** EPITECH PROJECT, 2021
** server
** File description:
** is_resource
*/

#include <criterion/criterion.h>

#include "server/request/checker.h"

Test(request_arg_check_is_resource, success)
{
    cr_assert(request_arg_check_is_resource("food"));
    cr_assert(request_arg_check_is_resource("linemate"));
    cr_assert(request_arg_check_is_resource("deraumere"));
    cr_assert(request_arg_check_is_resource("sibur"));
    cr_assert(request_arg_check_is_resource("mendiane"));
    cr_assert(request_arg_check_is_resource("phiras"));
    cr_assert(request_arg_check_is_resource("thystame"));
}

Test(request_arg_check_is_resource, failure)
{
    cr_assert(!request_arg_check_is_resource("  food"));
    cr_assert(!request_arg_check_is_resource("linemate  "));
    cr_assert(!request_arg_check_is_resource("deraumERe"));
    cr_assert(!request_arg_check_is_resource("deraubure"));
    cr_assert(!request_arg_check_is_resource(NULL));
}