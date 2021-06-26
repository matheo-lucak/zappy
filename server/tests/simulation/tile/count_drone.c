/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** add_item
*/

#include <criterion/criterion.h>
#include "simulation/drone.h"
#include "simulation/resources.h"
#include "simulation/tile.h"

Test(tile_count_drone, empty_tile)
{
    tile_t *tile = tile_create();

    cr_assert(tile_count_drone(tile) == 0);
    tile_destroy(tile);
}

Test(tile_count_drone, few_drone_on_tile)
{
    tile_t *tile = tile_create();
    drone_t *d1 = drone_create(0, 0);
    drone_t *d2 = drone_create(0, 0);
    drone_t *d3 = drone_create(0, 0);

    cr_assert(tile_count_drone(tile) == 0);
    cr_assert(tile_add_drone(tile, d1));
    cr_assert(tile_count_drone(tile) == 1);
    cr_assert(tile_add_drone(tile, d2));
    cr_assert(tile_count_drone(tile) == 2);
    cr_assert(tile_add_drone(tile, d3));
    cr_assert(tile_count_drone(tile) == 3);
    drone_destroy(d1);
    drone_destroy(d2);
    drone_destroy(d3);
    tile_destroy(tile);
}