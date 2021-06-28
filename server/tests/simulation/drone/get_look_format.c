/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** get_look_format
*/

#include <criterion/criterion.h>
#include "simulation/drone.h"
#include "simulation/map.h"

Test(drone_get_look_format, simple_get_look_left_lvl_1)
{
    map_t *map = map_create(10, 10);
    drone_t *drone = drone_create(5, 5, true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[drone->y][drone->x], drone));
    drone->facing_direction = LEFT;
    result = drone_get_look_format(map, drone);
    cr_expect_str_eq(result, "player,,,");
    free(result);
}

Test(drone_get_look_format, simple_get_look_left_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *drone = drone_create(5, 5, true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[drone->y][drone->x], drone));
    drone->facing_direction = LEFT;
    drone->elevation_lvl = 3;
    result = drone_get_look_format(map, drone);
    cr_expect_str_eq(result, "player,,,,,,,,,,,,,,,");
    free(result);
}

Test(drone_get_look_format, hard_1_get_look_left_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *drone = drone_create(5, 5, true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[drone->y][drone->x], drone));
    cr_assert(tile_add_item(map->tiles[6][4], RESOURCE_FOOD));
    drone->facing_direction = LEFT;
    drone->elevation_lvl = 3;
    result = drone_get_look_format(map, drone);
    cr_expect_str_eq(result, "player,food,,,,,,,,,,,,,,");
    free(result);
}

Test(drone_get_look_format, hard_2_get_look_left_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *drone = drone_create(5, 5, true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[drone->y][drone->x], drone));
    cr_assert(tile_add_item(map->tiles[6][4], RESOURCE_FOOD));
    cr_assert(tile_add_item(map->tiles[5][2], RESOURCE_THYSTAME));
    drone->facing_direction = LEFT;
    drone->elevation_lvl = 3;
    result = drone_get_look_format(map, drone);
    cr_expect_str_eq(result, "player,food,,,,,,,,,,,thystame,,,");
    free(result);
}

Test(drone_get_look_format, hard_3_get_look_left_lvl_2)
{
    map_t *map = map_create(10, 10);
    drone_t *drone = drone_create(5, 5, true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[drone->y][drone->x], drone));
    cr_assert(tile_add_item(map->tiles[6][4], RESOURCE_FOOD));
    cr_assert(tile_add_item(map->tiles[5][2], RESOURCE_THYSTAME));
    drone->facing_direction = LEFT;
    drone->elevation_lvl = 2;
    result = drone_get_look_format(map, drone);
    cr_expect_str_eq(result, "player,food,,,,,,,");
    free(result);
}

Test(drone_get_look_format, hard_4_get_look_left_lvl_2)
{
    map_t *map = map_create(10, 10);
    drone_t *drone = drone_create(5, 5, true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[drone->y][drone->x], drone));
    cr_assert(tile_add_item(map->tiles[6][4], RESOURCE_FOOD));
    cr_assert(tile_add_item(map->tiles[6][4], RESOURCE_FOOD));
    cr_assert(tile_add_item(map->tiles[6][4], RESOURCE_THYSTAME));
    drone->facing_direction = LEFT;
    drone->elevation_lvl = 2;
    result = drone_get_look_format(map, drone);
    cr_expect_str_eq(result, "player,food food thystame,,,,,,,");
    free(result);
}

Test(drone_get_look_format, hard_5_get_look_left_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *d1 = drone_create(5, 5, true);
    drone_t *d2 = drone_create(3, 4, true);
    drone_t *d3 = drone_create(2, 5, true);
    drone_t *d4 = drone_create(2, 5, true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[d1->y][d1->x], d1));
    d1->facing_direction = LEFT;
    d1->elevation_lvl = 3;
    cr_assert(tile_add_drone(map->tiles[d2->y][d2->x], d2));
    cr_assert(tile_add_drone(map->tiles[d3->y][d3->x], d3));
    cr_assert(tile_add_drone(map->tiles[d4->y][d4->x], d4));
    result = drone_get_look_format(map, d1);
    cr_expect_str_eq(result, "player,,,,,,,player,,,,,player player,,,");
    free(result);
}

Test(drone_get_look_format, hard_6_get_look_left_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *d1 = drone_create(0, 5, true);
    drone_t *d2 = drone_create(7, 5, true);
    drone_t *d3 = drone_create(7, 8, true);
    drone_t *d4 = drone_create(8, 8, true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[d1->y][d1->x], d1));
    d1->facing_direction = LEFT;
    d1->elevation_lvl = 3;
    cr_assert(tile_add_drone(map->tiles[d2->y][d2->x], d2));
    cr_assert(tile_add_drone(map->tiles[d3->y][d3->x], d3));
    cr_assert(tile_add_drone(map->tiles[d4->y][d4->x], d4));
    result = drone_get_look_format(map, d1);
    cr_expect_str_eq(result, "player,,,,,,,,,player,,,player,,,");
    free(result);
}

Test(drone_get_look_format, hard_7_get_look_left_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *d1 = drone_create(0, 7, true);
    drone_t *d2 = drone_create(7, 0, true);
    drone_t *d3 = drone_create(7, 5, true);
    drone_t *d4 = drone_create(7, 6, true);
    drone_t *d5 = drone_create(7, 8, true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[d1->y][d1->x], d1));
    d1->facing_direction = LEFT;
    d1->elevation_lvl = 3;
    cr_assert(tile_add_drone(map->tiles[d2->y][d2->x], d2));
    cr_assert(tile_add_drone(map->tiles[d3->y][d3->x], d3));
    cr_assert(tile_add_drone(map->tiles[d4->y][d4->x], d4));
    cr_assert(tile_add_drone(map->tiles[d5->y][d5->x], d5));
    result = drone_get_look_format(map, d1);
    cr_expect_str_eq(result, "player,,,,,,,,,player,,player,,player,player,");
    free(result);
}

Test(drone_get_look_format, simple_get_look_right_lvl_1)
{
    map_t *map = map_create(10, 10);
    drone_t *drone = drone_create(5, 5, true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[drone->y][drone->x], drone));
    drone->facing_direction = RIGHT;
    result = drone_get_look_format(map, drone);
    cr_expect_str_eq(result, "player,,,");
    free(result);
}

Test(drone_get_look_format, simple_get_look_right_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *drone = drone_create(5, 5, true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[drone->y][drone->x], drone));
    drone->facing_direction = RIGHT;
    drone->elevation_lvl = 3;
    result = drone_get_look_format(map, drone);
    cr_expect_str_eq(result, "player,,,,,,,,,,,,,,,");
    free(result);
}

Test(drone_get_look_format, hard_1_get_look_right_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *drone = drone_create(5, 5, true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[drone->y][drone->x], drone));
    cr_assert(tile_add_item(map->tiles[4][6], RESOURCE_FOOD));
    drone->facing_direction = RIGHT;
    drone->elevation_lvl = 3;
    result = drone_get_look_format(map, drone);
    cr_expect_str_eq(result, "player,food,,,,,,,,,,,,,,");
    free(result);
}

Test(drone_get_look_format, hard_2_get_look_right_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *drone = drone_create(5, 5, true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[drone->y][drone->x], drone));
    cr_assert(tile_add_item(map->tiles[4][6], RESOURCE_FOOD));
    cr_assert(tile_add_item(map->tiles[5][8], RESOURCE_THYSTAME));
    drone->facing_direction = RIGHT;
    drone->elevation_lvl = 3;
    result = drone_get_look_format(map, drone);
    cr_expect_str_eq(result, "player,food,,,,,,,,,,,thystame,,,");
    free(result);
}

Test(drone_get_look_format, hard_3_get_look_right_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *drone = drone_create(9, 5, true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[drone->y][drone->x], drone));
    cr_assert(tile_add_item(map->tiles[5][0], RESOURCE_FOOD));
    cr_assert(tile_add_item(map->tiles[3][2], RESOURCE_THYSTAME));
    drone->facing_direction = RIGHT;
    drone->elevation_lvl = 3;
    result = drone_get_look_format(map, drone);
    cr_expect_str_eq(result, "player,,food,,,,,,,,thystame,,,,,");
    free(result);
}

Test(drone_get_look_format, simple_get_look_up_lvl_1)
{
    map_t *map = map_create(10, 10);
    drone_t *drone = drone_create(5, 5, true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[drone->y][drone->x], drone));
    drone->facing_direction = UP;
    result = drone_get_look_format(map, drone);
    cr_expect_str_eq(result, "player,,,");
    free(result);
}

Test(drone_get_look_format, simple_get_look_up_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *drone = drone_create(5, 5, true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[drone->y][drone->x], drone));
    cr_assert(tile_add_item(map->tiles[4][4], RESOURCE_SIBUR));
    cr_assert(tile_add_item(map->tiles[2][5], RESOURCE_PHIRAS));
    drone->facing_direction = UP;
    drone->elevation_lvl = 3;
    result = drone_get_look_format(map, drone);
    cr_expect_str_eq(result, "player,sibur,,,,,,,,,,,phiras,,,");
    free(result);
}

Test(drone_get_look_format, simple_get_look_down_lvl_1)
{
    map_t *map = map_create(10, 10);
    drone_t *drone = drone_create(5, 5, true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[drone->y][drone->x], drone));
    drone->facing_direction = DOWN;
    result = drone_get_look_format(map, drone);
    cr_expect_str_eq(result, "player,,,");
    free(result);
}

Test(drone_get_look_format, hard_get_look_down_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *drone = drone_create(5, 5, true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[drone->y][drone->x], drone));
    cr_assert(tile_add_item(map->tiles[6][5], RESOURCE_SIBUR));
    cr_assert(tile_add_item(map->tiles[7][5], RESOURCE_PHIRAS));
    cr_assert(tile_add_item(map->tiles[7][5], RESOURCE_MENDIANE));
    cr_assert(tile_add_item(map->tiles[8][2], RESOURCE_FOOD));
    drone->facing_direction = DOWN;
    drone->elevation_lvl = 3;
    result = drone_get_look_format(map, drone);
    cr_expect_str_eq(result, "player,,sibur,,,,phiras mendiane,,,,,,,,,food");
    free(result);
}
