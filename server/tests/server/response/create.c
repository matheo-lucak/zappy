/*
** EPITECH PROJECT, 2021
** server
** File description:
** create
*/

#include <string.h>
#include <criterion/criterion.h>

#include "server/response/response.h"

Test(response_create, basic_drone_response_A)
{
    response_t *res1 = response_create(RESPONSE_WELCOME);
    response_t *res2 = response_create(RESPONSE_CLIENT_NUM, 5);
    response_t *res3 = response_create(RESPONSE_XY, 15, 29);
    response_t *res4 = response_create(RESPONSE_OK);
    response_t *res5 = response_create(RESPONSE_KO);
    response_t *res6 = response_create(RESPONSE_DEAD);

    cr_assert(res1 && !strcmp(res1->data, "WELCOME\n"));
    cr_assert(res2 && !strcmp(res2->data, "5\n"));
    cr_assert(res3 && !strcmp(res3->data, "15 29\n"));
    cr_assert(res4 && !strcmp(res4->data, "ok\n"));
    cr_assert(res5 && !strcmp(res5->data, "ko\n"));
    cr_assert(res6 && !strcmp(res6->data, "dead\n"));
    response_destroy(res1);
    response_destroy(res2);
    response_destroy(res3);
    response_destroy(res4);
    response_destroy(res5);
    response_destroy(res6);
}

Test(response_create, basic_drone_response_B)
{
    response_t *res1 = response_create(RESPONSE_LOOK, "player food,,, food");
    response_t *res2 = response_create(RESPONSE_INVENTORY, 12, 3, 2, 0, 1, 0, 1);
    response_t *res3 = response_create(RESPONSE_INCANTATION_START);
    response_t *res4 = response_create(RESPONSE_INCANTATION_ENDS, 6);

    cr_assert(res1 && !strcmp(res1->data, "[ player food,,, food ]\n"));
    cr_assert(res2 && !strcmp(res2->data,
        "[ food 12, linemate 3, deraumere 2,"\
        " sibur 0, mendiane 1, phiras 0, thystame 1 ]\n"));
    cr_assert(res3 && !strcmp(res3->data, "Elevation underway\n"));
    cr_assert(res4 && !strcmp(res4->data, "Current level: 6\n"));
    response_destroy(res1);
    response_destroy(res2);
    response_destroy(res3);
    response_destroy(res4);
}