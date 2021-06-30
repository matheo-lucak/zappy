/*
** EPITECH PROJECT, 2021
** server
** File description:
** create
*/

#include <criterion/criterion.h>

#include "simulation/map.h"

Test(map_create, basic_10_10)
{
    map_t *map = map_create(10, 10);

    cr_assert(map->expected[RESOURCE_FOOD] == 50);
    cr_assert(map->expected[RESOURCE_LINEMATE] == 30);
    cr_assert(map->expected[RESOURCE_DERAUMERE] == 15) ;
    cr_assert(map->expected[RESOURCE_SIBUR] == 10);
    cr_assert(map->expected[RESOURCE_MENDIANE] == 10);
    cr_assert(map->expected[RESOURCE_PHIRAS] == 8);
    cr_assert(map->expected[RESOURCE_THYSTAME] == 5);
    map_destroy(map);
}

Test(map_create, basic_refill)
{
    resource_quantities_t count = {0};
    map_t *map = map_create(10, 10);

    map_count_resources(map, &count);
    cr_assert(count[RESOURCE_FOOD] == 50);
    cr_assert(count[RESOURCE_LINEMATE] == 30);
    cr_assert(count[RESOURCE_DERAUMERE] == 15) ;
    cr_assert(count[RESOURCE_SIBUR] == 10);
    cr_assert(count[RESOURCE_MENDIANE] == 10);
    cr_assert(count[RESOURCE_PHIRAS] == 8);
    cr_assert(count[RESOURCE_THYSTAME] == 5);
    map_destroy(map);
}