/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** eject
*/

#include <criterion/criterion.h>
#include "simulation/drone.h"
#include "simulation/map.h"

Test(drone_eject, simple_ejection_right)
{
    drone_t *drone = drone_create(0, 0, true);
    map_t *map = map_create(10, 10);

    cr_assert(drone->x == 0);
    cr_assert(drone->y == 0);
    cr_assert(drone_eject(drone, map, RIGHT));
    cr_assert(drone->x == 1);
    cr_assert(drone->y == 0);
    drone_destroy(drone);
    map_destroy(map);
}

Test(drone_eject, simple_ejection_up_around_map)
{
    drone_t *drone = drone_create(0, 0, true);
    map_t *map = map_create(10, 10);

    cr_assert(drone->x == 0);
    cr_assert(drone->y == 0);
    cr_assert(drone_eject(drone, map, UP));
    cr_assert(drone->x == 0);
    cr_assert(drone->y == 9);
    drone_destroy(drone);
    map_destroy(map);
}

Test(drone_eject, simple_ejection_down_around_map)
{
    drone_t *drone = drone_create(9, 9, true);
    map_t *map = map_create(10, 10);

    cr_assert(drone->x == 9);
    cr_assert(drone->y == 9);
    cr_assert(drone_eject(drone, map, DOWN));
    cr_assert(drone->x == 9);
    cr_assert(drone->y == 0);
    drone_destroy(drone);
    map_destroy(map);
}
