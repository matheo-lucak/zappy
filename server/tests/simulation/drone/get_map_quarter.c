/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** get_map_quarter
*/

#include <criterion/criterion.h>
#include "simulation/map.h"
#include "simulation/drone.h"

Test(drone_get_map_quarter, simple_get_top_left_corner)
{
    map_t *map = map_create(10, 10);
    drone_t *drone = drone_create((vector2u_t){1, 1}, true);

    cr_expect(drone_get_map_quarter(drone, map) == MAP_TOP_LEFT);
    drone_destroy(drone);
    map_destroy(map);
}

Test(drone_get_map_quarter, hard_get_top_left_corner)
{
    map_t *map = map_create(10, 10);
    drone_t *drone = drone_create((vector2u_t){4, 4}, true);

    cr_expect(drone_get_map_quarter(drone, map) == MAP_TOP_LEFT);
    drone_destroy(drone);
    map_destroy(map);
}

Test(drone_get_map_quarter, simple_get_top_right_corner)
{
    map_t *map = map_create(10, 10);
    drone_t *drone = drone_create((vector2u_t){8, 1}, true);

    cr_expect(drone_get_map_quarter(drone, map) == MAP_TOP_RIGHT);
    drone_destroy(drone);
    map_destroy(map);
}


Test(drone_get_map_quarter, hard_get_top_right_corner)
{
    map_t *map = map_create(10, 10);
    drone_t *drone = drone_create((vector2u_t){5, 4}, true);

    cr_expect(drone_get_map_quarter(drone, map) == MAP_TOP_RIGHT);
    drone_destroy(drone);
    map_destroy(map);
}

Test(drone_get_map_quarter, simple_get_bottom_left_corner)
{
    map_t *map = map_create(10, 10);
    drone_t *drone = drone_create((vector2u_t){1, 8}, true);

    cr_expect(drone_get_map_quarter(drone, map) == MAP_BOTTOM_LEFT);
    drone_destroy(drone);
    map_destroy(map);
}

Test(drone_get_map_quarter, hard_get_bottom_left_corner)
{
    map_t *map = map_create(10, 10);
    drone_t *drone = drone_create((vector2u_t){4, 5}, true);

    cr_expect(drone_get_map_quarter(drone, map) == MAP_BOTTOM_LEFT);
    drone_destroy(drone);
    map_destroy(map);
}

Test(drone_get_map_quarter, simple_get_bottom_right_corner)
{
    map_t *map = map_create(10, 10);
    drone_t *drone = drone_create((vector2u_t){8, 8}, true);

    cr_expect(drone_get_map_quarter(drone, map) == MAP_BOTTOM_RIGHT);
    drone_destroy(drone);
    map_destroy(map);
}

Test(drone_get_map_quarter, hard_get_bottom_right_corner)
{
    map_t *map = map_create(10, 10);
    drone_t *drone = drone_create((vector2u_t){5, 5}, true);

    cr_expect(drone_get_map_quarter(drone, map) == MAP_BOTTOM_RIGHT);
    drone_destroy(drone);
    map_destroy(map);
}
