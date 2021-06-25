/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace) [WSL: Ubuntu]
** File description:
** move
*/

#include <criterion/criterion.h>
#include "simulation/drone.h"

Test(drone_move, small_easy_move_in_x)
{
    drone_t *drone = drone_create(0, 0, true);
    map_t *map = map_create(10, 10);

    drone->facing_direction = RIGHT;
    cr_assert(drone_move(drone, map));
    cr_assert(drone->x == 1);
    cr_assert(drone->y == 0);
}

Test(drone_move, small_easy_move_in_y)
{
    drone_t *drone = drone_create(0, 0, true);
    map_t *map = map_create(10, 10);

    drone->facing_direction = DOWN;
    cr_assert(drone_move(drone, map));
    cr_assert(drone->x == 0);
    cr_assert(drone->y == 1);
}

Test(drone_move, return_to_upper_left_from_upper_right)
{
    drone_t *drone = drone_create(9, 0);
    map_t *map = map_create(10, 10);

    drone->facing_direction = RIGHT;
    cr_assert(drone_move(drone, map));
    cr_assert(drone->x == 0);
    cr_assert(drone->y == 0);
}

Test(drone_move, return_to_upper_right_from_upper_left)
{
    drone_t *drone = drone_create(0, 0, true);
    map_t *map = map_create(10, 10);

    drone->facing_direction = LEFT;
    cr_assert(drone_move(drone, map));
    cr_assert(drone->x == 9);
    cr_assert(drone->y == 0);
}

Test(drone_move, return_to_lower_left_from_lower_right)
{
    drone_t *drone = drone_create(9, 9);
    map_t *map = map_create(10, 10);

    drone->facing_direction = RIGHT;
    cr_assert(drone_move(drone, map));
    cr_assert(drone->x == 0);
    cr_assert(drone->y == 9);
}

Test(drone_move, return_to_lower_right_from_lower_left)
{
    drone_t *drone = drone_create(0, 9);
    map_t *map = map_create(10, 10);

    drone->facing_direction = LEFT;
    cr_assert(drone_move(drone, map));
    cr_assert(drone->x == 9);
    cr_assert(drone->y == 9);
}

Test(drone_move, return_to_lower_right_from_upper_right)
{
    drone_t *drone = drone_create(9, 0);
    map_t *map = map_create(10, 10);

    drone->facing_direction = UP;
    cr_assert(drone_move(drone, map));
    cr_assert(drone->x == 9);
    cr_assert(drone->y == 9);
}

Test(drone_move, return_to_upper_right_from_lower_right)
{
    drone_t *drone = drone_create(9, 9);
    map_t *map = map_create(10, 10);

    drone->facing_direction = DOWN;
    cr_assert(drone_move(drone, map));
    cr_assert(drone->x == 9);
    cr_assert(drone->y == 0);
}
