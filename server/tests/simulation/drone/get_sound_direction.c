/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** get_sound_direction
*/

#include <criterion/criterion.h>
#include "simulation/drone.h"

Test(drone_get_sound_direction, simple_straight_line_direction_1)
{
    map_t *map = map_create(10, 10);
    drone_t *d1 = drone_create(VEC2U(4, 4), true);
    drone_t *d2 = drone_create(VEC2U(7, 4), true);

    d2->facing_direction = LEFT;
    cr_expect(drone_get_sound_direction(map, d1, d2) == LCL_UP);
    map_destroy(map);
    drone_destroy(d1);
    drone_destroy(d2);
}

Test(drone_get_sound_direction, simple_straight_line_direction_2)
{
    map_t *map = map_create(10, 10);
    drone_t *d1 = drone_create(VEC2U(4, 4), true);
    drone_t *d2 = drone_create(VEC2U(7, 4), true);

    d2->facing_direction = UP;
    cr_expect(drone_get_sound_direction(map, d1, d2) == LCL_LEFT);
    map_destroy(map);
    drone_destroy(d1);
    drone_destroy(d2);
}

Test(drone_get_sound_direction, simple_straight_line_direction_3)
{
    map_t *map = map_create(10, 10);
    drone_t *d1 = drone_create(VEC2U(4, 4), true);
    drone_t *d2 = drone_create(VEC2U(7, 4), true);

    d2->facing_direction = RIGHT;
    cr_expect(drone_get_sound_direction(map, d1, d2) == LCL_DOWN);
    map_destroy(map);
    drone_destroy(d1);
    drone_destroy(d2);
}

Test(drone_get_sound_direction, simple_straight_line_direction_4)
{
    map_t *map = map_create(10, 10);
    drone_t *d1 = drone_create(VEC2U(4, 4), true);
    drone_t *d2 = drone_create(VEC2U(7, 4), true);

    d2->facing_direction = DOWN;
    cr_expect(drone_get_sound_direction(map, d1, d2) == LCL_RIGHT);
    map_destroy(map);
    drone_destroy(d1);
    drone_destroy(d2);
}

Test(drone_get_sound_direction, simple_same_location)
{
    map_t *map = map_create(10, 10);
    drone_t *d1 = drone_create(VEC2U(4, 4), true);
    drone_t *d2 = drone_create(VEC2U(4, 4), true);

    d2->facing_direction = LEFT;
    cr_expect(drone_get_sound_direction(map, d1, d2) == LCL_HERE);
    map_destroy(map);
    drone_destroy(d1);
    drone_destroy(d2);
}

Test(drone_get_sound_direction, hard_subject_test)
{
    map_t *map = map_create(10, 11);
    drone_t *d1 = drone_create(VEC2U(2, 9), true);
    drone_t *d2 = drone_create(VEC2U(5, 2), true);

    d2->facing_direction = RIGHT;
    cr_expect(drone_get_sound_direction(map, d1, d2) == LCL_DOWN_LEFT);
    map_destroy(map);
    drone_destroy(d1);
    drone_destroy(d2);
}

Test(drone_get_sound_direction, hard_bottom_left_diagonal)
{
    map_t *map = map_create(10, 10);
    drone_t *d1 = drone_create(VEC2U(1, 9), true);
    drone_t *d2 = drone_create(VEC2U(8, 2), true);

    d2->facing_direction = DOWN;
    cr_expect(drone_get_sound_direction(map, d1, d2) == LCL_DOWN_LEFT);
    map_destroy(map);
    drone_destroy(d1);
    drone_destroy(d2);
}
