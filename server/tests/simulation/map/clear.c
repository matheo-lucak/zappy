/*
** EPITECH PROJECT, 2021
** server
** File description:
** create
*/

#include <criterion/criterion.h>

#include "simulation/map.h"

Test(map_clear_resources, basic)
{
    map_t *map = map_create(10, 10);
    resource_quantities_t count = {0};

    map_clear_resources(map);
    map_count_resources(map, &count);
    cr_assert(count[RESOURCE_FOOD] == 0);
    cr_assert(count[RESOURCE_LINEMATE] == 0);
    cr_assert(count[RESOURCE_DERAUMERE] == 0) ;
    cr_assert(count[RESOURCE_SIBUR] == 0);
    cr_assert(count[RESOURCE_MENDIANE] == 0);
    cr_assert(count[RESOURCE_PHIRAS] == 0);
    cr_assert(count[RESOURCE_THYSTAME] == 0);
    map_destroy(map);
}