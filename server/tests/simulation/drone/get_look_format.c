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
    drone_t *d = drone_create(VEC2U(5, 5), true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[d->y][d->x], d));
    d->facing_direction = LEFT;
    result = drone_get_look_format(map, d);
    cr_expect_str_eq(result, "player,,,");
    free(result);
}

Test(drone_get_look_format, simple_get_look_left_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *d = drone_create(VEC2U(5, 5), true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[d->y][d->x], d));
    d->facing_direction = LEFT;
    d->elevation_lvl = 3;
    result = drone_get_look_format(map, d);
    cr_expect_str_eq(result, "player,,,,,,,,,,,,,,,");
    free(result);
}

Test(drone_get_look_format, hard_1_get_look_left_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *d = drone_create(VEC2U(5, 5), true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[d->y][d->x], d));
    cr_assert(tile_add_item(map->tiles[6][4], RESOURCE_FOOD));
    d->facing_direction = LEFT;
    d->elevation_lvl = 3;
    result = drone_get_look_format(map, d);
    cr_expect_str_eq(result, "player,food,,,,,,,,,,,,,,");
    free(result);
}

Test(drone_get_look_format, hard_2_get_look_left_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *d = drone_create(VEC2U(5, 5), true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[d->pos.y][d->pos.x], d));
    cr_assert(tile_add_item(map->tiles[6][4], RESOURCE_FOOD));
    cr_assert(tile_add_item(map->tiles[5][2], RESOURCE_THYSTAME));
    d->facing_direction = LEFT;
    d->elevation_lvl = 3;
    result = drone_get_look_format(map, d);
    cr_expect_str_eq(result, "player,food,,,,,,,,,,,thystame,,,");
    free(result);
}

Test(drone_get_look_format, hard_3_get_look_left_lvl_2)
{
    map_t *map = map_create(10, 10);
    drone_t *d = drone_create(VEC2U(5, 5), true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[d->pos.y][d->pos.x], d));
    cr_assert(tile_add_item(map->tiles[6][4], RESOURCE_FOOD));
    cr_assert(tile_add_item(map->tiles[5][2], RESOURCE_THYSTAME));
    d->facing_direction = LEFT;
    d->elevation_lvl = 2;
    result = drone_get_look_format(map, d);
    cr_expect_str_eq(result, "player,food,,,,,,,");
    free(result);
}

Test(drone_get_look_format, hard_4_get_look_left_lvl_2)
{
    map_t *map = map_create(10, 10);
    drone_t *d = drone_create(VEC2U(5, 5), true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[d->pos.y][d->pos.x], d));
    cr_assert(tile_add_item(map->tiles[6][4], RESOURCE_FOOD));
    cr_assert(tile_add_item(map->tiles[6][4], RESOURCE_FOOD));
    cr_assert(tile_add_item(map->tiles[6][4], RESOURCE_THYSTAME));
    d->facing_direction = LEFT;
    d->elevation_lvl = 2;
    result = drone_get_look_format(map, d);
    cr_expect_str_eq(result, "player,food food thystame,,,,,,,");
    free(result);
}

Test(drone_get_look_format, hard_5_get_look_left_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *d1 = drone_create(VEC2U(5, 5), true);
    drone_t *d2 = drone_create(VEC2U(3, 4), true);
    drone_t *d3 = drone_create(VEC2U(2, 5), true);
    drone_t *d4 = drone_create(VEC2U(2, 5), true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[d1->pos.y][d1->pos.x], d1));
    d1->facing_direction = LEFT;
    d1->elevation_lvl = 3;
    cr_assert(tile_add_drone(map->tiles[d2->pos.y][d2->pos.x], d2));
    cr_assert(tile_add_drone(map->tiles[d3->pos.y][d3->pos.x], d3));
    cr_assert(tile_add_drone(map->tiles[d4->pos.y][d4->pos.x], d4));
    result = drone_get_look_format(map, d1);
    cr_expect_str_eq(result, "player,,,,,,,player,,,,,player player,,,");
    free(result);
}

Test(drone_get_look_format, hard_6_get_look_left_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *d1 = drone_create(VEC2U(0, 5), true);
    drone_t *d2 = drone_create(VEC2U(7, 5), true);
    drone_t *d3 = drone_create(VEC2U(7, 8), true);
    drone_t *d4 = drone_create(VEC2U(8, 8), true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[d1->pos.y][d1->pos.x], d1));
    d1->facing_direction = LEFT;
    d1->elevation_lvl = 3;
    cr_assert(tile_add_drone(map->tiles[d2->pos.y][d2->pos.x], d2));
    cr_assert(tile_add_drone(map->tiles[d3->pos.y][d3->pos.x], d3));
    cr_assert(tile_add_drone(map->tiles[d4->pos.y][d4->pos.x], d4));
    result = drone_get_look_format(map, d1);
    cr_expect_str_eq(result, "player,,,,,,,,,player,,,player,,,");
    free(result);
}

Test(drone_get_look_format, hard_7_get_look_left_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *d1 = drone_create(VEC2U(0, 7), true);
    drone_t *d2 = drone_create(VEC2U(7, 0), true);
    drone_t *d3 = drone_create(VEC2U(7, 5), true);
    drone_t *d4 = drone_create(VEC2U(7, 6), true);
    drone_t *d5 = drone_create(VEC2U(7, 8), true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[d1->pos.y][d1->pos.x], d1));
    d1->facing_direction = LEFT;
    d1->elevation_lvl = 3;
    cr_assert(tile_add_drone(map->tiles[d2->pos.y][d2->pos.x], d2));
    cr_assert(tile_add_drone(map->tiles[d3->pos.y][d3->pos.x], d3));
    cr_assert(tile_add_drone(map->tiles[d4->pos.y][d4->pos.x], d4));
    cr_assert(tile_add_drone(map->tiles[d5->pos.y][d5->pos.x], d5));
    result = drone_get_look_format(map, d1);
    cr_expect_str_eq(result, "player,,,,,,,,,player,,player,,player,player,");
    free(result);
}

Test(drone_get_look_format, simple_get_look_right_lvl_1)
{
    map_t *map = map_create(10, 10);
    drone_t *d = drone_create(VEC2U(5, 5), true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[d->pos.y][d->pos.x], d));
    d->facing_direction = RIGHT;
    result = drone_get_look_format(map, d);
    cr_expect_str_eq(result, "player,,,");
    free(result);
}

Test(drone_get_look_format, simple_get_look_right_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *d = drone_create(VEC2U(5, 5), true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[d->pos.y][d->pos.x], d));
    d->facing_direction = RIGHT;
    d->elevation_lvl = 3;
    result = drone_get_look_format(map, d);
    cr_expect_str_eq(result, "player,,,,,,,,,,,,,,,");
    free(result);
}

Test(drone_get_look_format, hard_1_get_look_right_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *d = drone_create(VEC2U(5, 5), true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[d->pos.y][d->pos.x], d));
    cr_assert(tile_add_item(map->tiles[4][6], RESOURCE_FOOD));
    d->facing_direction = RIGHT;
    d->elevation_lvl = 3;
    result = drone_get_look_format(map, d);
    cr_expect_str_eq(result, "player,food,,,,,,,,,,,,,,");
    free(result);
}

Test(drone_get_look_format, hard_2_get_look_right_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *d = drone_create(VEC2U(5, 5), true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[d->pos.y][d->pos.x], d));
    cr_assert(tile_add_item(map->tiles[4][6], RESOURCE_FOOD));
    cr_assert(tile_add_item(map->tiles[5][8], RESOURCE_THYSTAME));
    d->facing_direction = RIGHT;
    d->elevation_lvl = 3;
    result = drone_get_look_format(map, d);
    cr_expect_str_eq(result, "player,food,,,,,,,,,,,thystame,,,");
    free(result);
}

Test(drone_get_look_format, hard_3_get_look_right_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *d = drone_create(VEC2U(9, 5), true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[d->pos.y][d->pos.x], d));
    cr_assert(tile_add_item(map->tiles[5][0], RESOURCE_FOOD));
    cr_assert(tile_add_item(map->tiles[3][2], RESOURCE_THYSTAME));
    d->facing_direction = RIGHT;
    d->elevation_lvl = 3;
    result = drone_get_look_format(map, d);
    cr_expect_str_eq(result, "player,,food,,,,,,,,thystame,,,,,");
    free(result);
}

Test(drone_get_look_format, simple_get_look_up_lvl_1)
{
    map_t *map = map_create(10, 10);
    drone_t *d = drone_create(VEC2U(5, 5), true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[d->pos.y][d->pos.x], d));
    d->facing_direction = UP;
    result = drone_get_look_format(map, d);
    cr_expect_str_eq(result, "player,,,");
    free(result);
}

Test(drone_get_look_format, simple_get_look_up_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *d = drone_create(VEC2U(5, 5), true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[d->pos.y][d->pos.x], d));
    cr_assert(tile_add_item(map->tiles[4][4], RESOURCE_SIBUR));
    cr_assert(tile_add_item(map->tiles[2][5], RESOURCE_PHIRAS));
    d->facing_direction = UP;
    d->elevation_lvl = 3;
    result = drone_get_look_format(map, d);
    cr_expect_str_eq(result, "player,sibur,,,,,,,,,,,phiras,,,");
    free(result);
}

Test(drone_get_look_format, simple_get_look_down_lvl_1)
{
    map_t *map = map_create(10, 10);
    drone_t *d = drone_create(VEC2U(5, 5), true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[d->pos.y][d->pos.x], d));
    d->facing_direction = DOWN;
    result = drone_get_look_format(map, d);
    cr_expect_str_eq(result, "player,,,");
    free(result);
}

Test(drone_get_look_format, hard_get_look_down_lvl_3)
{
    map_t *map = map_create(10, 10);
    drone_t *d = drone_create(VEC2U(5, 5), true);
    char *result = NULL;

    map_clear_resources(map);
    cr_assert(tile_add_drone(map->tiles[d->pos.y][d->pos.x], d));
    cr_assert(tile_add_item(map->tiles[6][5], RESOURCE_SIBUR));
    cr_assert(tile_add_item(map->tiles[7][5], RESOURCE_PHIRAS));
    cr_assert(tile_add_item(map->tiles[7][5], RESOURCE_MENDIANE));
    cr_assert(tile_add_item(map->tiles[8][2], RESOURCE_FOOD));
    d->facing_direction = DOWN;
    d->elevation_lvl = 3;
    result = drone_get_look_format(map, d);
    cr_expect_str_eq(result, "player,,sibur,,,,phiras mendiane,,,,,,,,,food");
    free(result);
}
