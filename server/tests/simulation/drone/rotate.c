/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace) [WSL: Ubuntu]
** File description:
** rotate
*/

#include <criterion/criterion.h>

#include "simulation/drone.h"

Test(drone_rotate, simple_circular_left_rotation)
{
    drone_t *drone = drone_create(VEC2U(0, 0), true);

    drone->facing_direction = LEFT;
    drone_rotate(drone, LEFT);
    cr_assert(drone->facing_direction == DOWN);
    drone_rotate(drone, LEFT);
    cr_assert(drone->facing_direction == RIGHT);
    drone_rotate(drone, LEFT);
    cr_assert(drone->facing_direction == UP);
    drone_rotate(drone, LEFT);
    cr_assert(drone->facing_direction == LEFT);
}
