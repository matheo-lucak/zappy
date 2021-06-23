/*
** EPITECH PROJECT, 2021
** server
** File description:
** checker
*/

#include <criterion/criterion.h>

#include "server/request/request.h"

Test(request_checker, basic_request_1)
{
    client_t *c = client_create();
    request_t *r = request_parse_from_input("Forward");

    client_to_drone(c, drone_create(0, 0));
    cr_assert(c && r);
    cr_assert(r->is_valid);
    cr_assert(request_checker(c, r));
}

Test(request_checker, basic_request_2)
{
    client_t *c = client_create();
    request_t *r = request_parse_from_input("msz");

    client_to_spectator(c);
    cr_assert(c && r);
    cr_assert(r->is_valid);
    cr_assert(request_checker(c, r));
}

Test(request_checker, basic_request_w_arg_1)
{
    client_t *c = client_create();
    request_t *r = request_parse_from_input("Take food");

    client_to_drone(c, drone_create(0, 0));
    cr_assert(c && r);
    cr_assert(r->is_valid);
    cr_assert(request_checker(c, r));
}

Test(request_checker, basic_request_w_arg_2)
{
    client_t *c = client_create();
    request_t *r = request_parse_from_input("bct 09 13");

    client_to_spectator(c);
    cr_assert(c && r);
    cr_assert(r->is_valid);
    cr_assert(request_checker(c, r));
}

Test(request_checker, basic_request_w_arg_3)
{
    client_t *c = client_create();
    request_t *r = request_parse_from_input("pin 125");

    client_to_spectator(c);
    cr_assert(c && r);
    cr_assert(r->is_valid);
    cr_assert(request_checker(c, r));
}

Test(request_checker, bad_request_arg_nb_1)
{
    client_t *c = client_create();
    request_t *r = request_parse_from_input("Forward hello");

    client_to_drone(c, drone_create(0, 0));
    cr_assert(c && r);
    cr_assert(r->is_valid);
    cr_assert(request_checker(c, r));
}

Test(request_checker, bad_request_arg_nb_2)
{
    client_t *c = client_create();
    request_t *r = request_parse_from_input("Take food food food");

    client_to_drone(c, drone_create(0, 0));
    cr_assert(c && r);
    cr_assert(r->is_valid);
    cr_assert(request_checker(c, r));
}

Test(request_checker, bad_request_arg_nb_3)
{
    client_t *c = client_create();
    request_t *r = request_parse_from_input("Take");

    client_to_drone(c, drone_create(0, 0));
    cr_assert(c && r);
    cr_assert(r->is_valid);
    cr_assert(!request_checker(c, r));
}

Test(request_checker, bad_request_arg_1)
{
    client_t *c = client_create();
    request_t *r = request_parse_from_input("Take foodo");

    client_to_drone(c, drone_create(0, 0));
    cr_assert(c && r);
    cr_assert(r->is_valid);
    cr_assert(!request_checker(c, r));
}

Test(request_checker, bad_request_arg_2)
{
    client_t *c = client_create();
    request_t *r = request_parse_from_input("pin 01a");

    client_to_spectator(c);
    cr_assert(c && r);
    cr_assert(r->is_valid);
    cr_assert(!request_checker(c, r));
}

Test(request_checker, bad_request_arg_3)
{
    client_t *c = client_create();
    request_t *r = request_parse_from_input("pin -105");

    client_to_spectator(c);
    cr_assert(c && r);
    cr_assert(r->is_valid);
    cr_assert(!request_checker(c, r));
}

Test(request_checker, bad_request_client_type_1)
{
    client_t *c = client_create();
    request_t *r = request_parse_from_input("pin 102");

    client_to_drone(c, drone_create(0, 0));
    cr_assert(c && r);
    cr_assert(r->is_valid);
    cr_assert(!request_checker(c, r));
}

Test(request_checker, bad_request_client_type_2)
{
    client_t *c = client_create();
    request_t *r = request_parse_from_input("msz");

    client_to_drone(c, drone_create(0, 0));
    cr_assert(c && r);
    cr_assert(r->is_valid);
    cr_assert(!request_checker(c, r));
}

Test(request_checker, bad_request_client_type_3)
{
    client_t *c = client_create();
    request_t *r = request_parse_from_input("Forward");

    client_to_spectator(c);
    cr_assert(c && r);
    cr_assert(r->is_valid);
    cr_assert(!request_checker(c, r));
}