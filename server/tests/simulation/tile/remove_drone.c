/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** add_drone
*/

#include <criterion/criterion.h>
#include "simulation/drone.h"
#include "simulation/tile.h"

Test(tile_remove_drone, simple_remove_drone)
{
    tile_t *tile = tile_create();
    drone_t *drone = drone_create(0, 0);

    cr_assert(!ptr_list_find(tile->drones, drone));
    cr_assert(tile_add_drone(tile, drone));
    cr_assert(ptr_list_find(tile->drones, drone));
    cr_assert(tile_remove_drone(tile, drone));
    cr_assert(!ptr_list_find(tile->drones, drone));
    tile_destroy(tile);
    drone_destroy(drone);
}

Test(tile_remove_drone, several_remove_drone)
{
    tile_t *tile = tile_create();
    drone_t *drone = drone_create(0, 0);

    cr_assert(!ptr_list_find(tile->drones, drone));
    cr_assert(tile_add_drone(tile, drone));
    cr_assert(ptr_list_find(tile->drones, drone));
    cr_assert(tile_remove_drone(tile, drone));
    cr_assert(!ptr_list_find(tile->drones, drone));
    cr_assert(!tile_remove_drone(tile, drone));
    tile_destroy(tile);
    drone_destroy(drone);
}
