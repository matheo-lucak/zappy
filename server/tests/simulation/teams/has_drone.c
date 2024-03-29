/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** has_drone
*/

#include <criterion/criterion.h>
#include "simulation/team.h"

Test(team_has_drone, basic_tests)
{
    team_t *t = team_create("Hello", 5);
    drone_t *d = drone_create(VEC2U(0, 0), true);

    cr_assert(t);
    cr_assert(team_has_drone(t, d) == false);
    cr_assert(team_add_drone(t, drone_create(VEC2U(0, 0), true)));
    cr_assert(team_has_drone(t, d) == false);
    cr_assert(team_add_drone(t, d) == true);
    cr_assert(team_has_drone(t, d) == true);
    cr_assert(team_add_drone(t, drone_create(VEC2U(0, 0), true)));
    cr_assert(team_add_drone(t, drone_create(VEC2U(0, 0), true)));
    cr_assert(team_add_drone(t, drone_create(VEC2U(0, 0), true)));
    cr_assert(team_has_drone(t, d) == true);
    team_destroy(t);
}