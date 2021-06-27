/*
** EPITECH PROJECT, 2021
** server
** File description:
** check
*/

#include <criterion/criterion.h>

#include "simulation/incantation.h"

static void setup_dummy_tile_drone(tile_t *tile, drone_t **drone_tab, size_t drone_nb,
                                                                    size_t drone_lvl)
{
    for (size_t i = 0; i < drone_nb; i++) {
        drone_tab[i] = drone_create(0, 0, true);
        drone_tab[i]->elevation_lvl = drone_lvl;
        tile_add_drone(tile, drone_tab[i]);
    }
}

static void clear_dummy_tile_drone(tile_t *tile, drone_t **drone_tab, size_t drone_nb)
{
    for (size_t i = 0; i < drone_nb; i++) {
        drone_destroy(drone_tab[i]);
    }
}


static void setup_dummy_tile_resource(tile_t *tile, resource_type_t type,
                                                        size_t resource_nb)
{
    for (size_t i = 0; i < resource_nb; i++) {
        tile_add_item(tile, type);
    }
}

Test(incantation_check_requirements, basic_lvl_1)
{
    tile_t *tile = tile_create();
    size_t drone_nb = 1;
    drone_t *drone_tab[drone_nb];
    incantation_t *inc = NULL;

    setup_dummy_tile_drone(tile, drone_tab, drone_nb, 1);
    inc =  incantation_create(drone_tab[0], tile);
    setup_dummy_tile_resource(tile, RESOURCE_LINEMATE, 1);
    cr_assert(incantation_check_requirements(inc) == true);
    clear_dummy_tile_drone(tile, drone_tab, drone_nb);
    tile_destroy(tile);
}

Test(incantation_check_requirements, basic_lvl_2)
{
    tile_t *tile = tile_create();
    size_t drone_nb = 2;
    drone_t *drone_tab[drone_nb];
    incantation_t *inc = NULL;

    setup_dummy_tile_drone(tile, drone_tab, drone_nb, 2);
    inc =  incantation_create(drone_tab[0], tile);
    setup_dummy_tile_resource(tile, RESOURCE_LINEMATE, 1);
    setup_dummy_tile_resource(tile, RESOURCE_DERAUMERE, 1);
    setup_dummy_tile_resource(tile, RESOURCE_SIBUR, 1);
    cr_assert(incantation_check_requirements(inc) == true);
    clear_dummy_tile_drone(tile, drone_tab, drone_nb);
    tile_destroy(tile);
}

Test(incantation_check_requirements, basic_lvl_3)
{
    tile_t *tile = tile_create();
    size_t drone_nb = 2;
    drone_t *drone_tab[drone_nb];
    incantation_t *inc = NULL;

    setup_dummy_tile_drone(tile, drone_tab, drone_nb, 3);
    inc =  incantation_create(drone_tab[0], tile);
    setup_dummy_tile_resource(tile, RESOURCE_LINEMATE, 2);
    setup_dummy_tile_resource(tile, RESOURCE_SIBUR, 1);
    setup_dummy_tile_resource(tile, RESOURCE_PHIRAS, 2);
    cr_assert(incantation_check_requirements(inc) == true);
    clear_dummy_tile_drone(tile, drone_tab, drone_nb);
    tile_destroy(tile);
}

Test(incantation_check_requirements, basic_lvl_4)
{
    tile_t *tile = tile_create();
    size_t drone_nb = 4;
    drone_t *drone_tab[drone_nb];
    incantation_t *inc = NULL;

    setup_dummy_tile_drone(tile, drone_tab, drone_nb, 4);
    inc =  incantation_create(drone_tab[0], tile);
    setup_dummy_tile_resource(tile, RESOURCE_LINEMATE, 1);
    setup_dummy_tile_resource(tile, RESOURCE_DERAUMERE, 1);
    setup_dummy_tile_resource(tile, RESOURCE_SIBUR, 2);
    setup_dummy_tile_resource(tile, RESOURCE_PHIRAS, 1);
    cr_assert(incantation_check_requirements(inc) == true);
    clear_dummy_tile_drone(tile, drone_tab, drone_nb);
    tile_destroy(tile);
}

Test(incantation_check_requirements, basic_lvl_5)
{
    tile_t *tile = tile_create();
    size_t drone_nb = 4;
    drone_t *drone_tab[drone_nb];
    incantation_t *inc = NULL;

    setup_dummy_tile_drone(tile, drone_tab, drone_nb, 5);
    inc =  incantation_create(drone_tab[0], tile);
    setup_dummy_tile_resource(tile, RESOURCE_LINEMATE, 1);
    setup_dummy_tile_resource(tile, RESOURCE_DERAUMERE, 2);
    setup_dummy_tile_resource(tile, RESOURCE_SIBUR, 1);
    setup_dummy_tile_resource(tile, RESOURCE_MENDIANE, 3);
    cr_assert(incantation_check_requirements(inc) == true);
    clear_dummy_tile_drone(tile, drone_tab, drone_nb);
    tile_destroy(tile);
}

Test(incantation_check_requirements, basic_lvl_6)
{
    tile_t *tile = tile_create();
    size_t drone_nb = 6;
    drone_t *drone_tab[drone_nb];
    incantation_t *inc = NULL;

    setup_dummy_tile_drone(tile, drone_tab, drone_nb, 6);
    inc =  incantation_create(drone_tab[0], tile);
    setup_dummy_tile_resource(tile, RESOURCE_LINEMATE, 1);
    setup_dummy_tile_resource(tile, RESOURCE_DERAUMERE, 2);
    setup_dummy_tile_resource(tile, RESOURCE_SIBUR, 3);
    setup_dummy_tile_resource(tile, RESOURCE_PHIRAS, 1);
    cr_assert(incantation_check_requirements(inc) == true);
    clear_dummy_tile_drone(tile, drone_tab, drone_nb);
    tile_destroy(tile);
}

Test(incantation_check_requirements, basic_lvl_7)
{
    tile_t *tile = tile_create();
    size_t drone_nb = 6;
    drone_t *drone_tab[drone_nb];
    incantation_t *inc = NULL;

    setup_dummy_tile_drone(tile, drone_tab, drone_nb, 7);
    inc =  incantation_create(drone_tab[0], tile);
    setup_dummy_tile_resource(tile, RESOURCE_LINEMATE, 2);
    setup_dummy_tile_resource(tile, RESOURCE_DERAUMERE, 2);
    setup_dummy_tile_resource(tile, RESOURCE_SIBUR, 2);
    setup_dummy_tile_resource(tile, RESOURCE_MENDIANE, 2);
    setup_dummy_tile_resource(tile, RESOURCE_PHIRAS, 2);
    setup_dummy_tile_resource(tile, RESOURCE_THYSTAME, 1);
    cr_assert(incantation_check_requirements(inc) == true);
    clear_dummy_tile_drone(tile, drone_tab, drone_nb);
    tile_destroy(tile);
}

Test(incantation_check_requirements, too_many_player_1)
{
    tile_t *tile = tile_create();
    size_t drone_nb = 1;
    drone_t *drone_tab[drone_nb];
    incantation_t *inc = NULL;

    setup_dummy_tile_drone(tile, drone_tab, drone_nb, 2);
    inc =  incantation_create(drone_tab[0], tile);
    setup_dummy_tile_resource(tile, RESOURCE_LINEMATE, 1);
    cr_assert(incantation_check_requirements(inc) == false);
    clear_dummy_tile_drone(tile, drone_tab, drone_nb);
    tile_destroy(tile);
}


Test(incantation_check_requirements, too_many_player_2)
{
    tile_t *tile = tile_create();
    size_t drone_nb = 4;
    drone_t *drone_tab[drone_nb];
    incantation_t *inc = NULL;

    setup_dummy_tile_drone(tile, drone_tab, drone_nb, 5);
    inc =  incantation_create(drone_tab[0], tile);
    setup_dummy_tile_resource(tile, RESOURCE_LINEMATE, 1);
    setup_dummy_tile_resource(tile, RESOURCE_DERAUMERE, 1);
    setup_dummy_tile_resource(tile, RESOURCE_SIBUR, 2);
    setup_dummy_tile_resource(tile, RESOURCE_PHIRAS, 1);
    cr_assert(incantation_check_requirements(inc) == false);
    clear_dummy_tile_drone(tile, drone_tab, drone_nb);
    tile_destroy(tile);
}

Test(incantation_check_requirements, not_enough_player_1)
{
    tile_t *tile = tile_create();
    size_t drone_nb = 4;
    drone_t *drone_tab[drone_nb];
    incantation_t *inc = NULL;

    setup_dummy_tile_drone(tile, drone_tab, drone_nb, 5);
    inc =  incantation_create(drone_tab[0], tile);
    setup_dummy_tile_resource(tile, RESOURCE_LINEMATE, 1);
    setup_dummy_tile_resource(tile, RESOURCE_DERAUMERE, 1);
    setup_dummy_tile_resource(tile, RESOURCE_SIBUR, 2);
    setup_dummy_tile_resource(tile, RESOURCE_PHIRAS, 1);
    cr_assert(incantation_check_requirements(inc) == false);
    clear_dummy_tile_drone(tile, drone_tab, drone_nb);
    tile_destroy(tile);
}

Test(incantation_check_requirements, bad_level)
{
    tile_t *tile = tile_create();
    size_t drone_nb = 4;
    drone_t *drone_tab[drone_nb];
    incantation_t *inc = NULL;

    setup_dummy_tile_drone(tile, drone_tab, drone_nb, 6);
    inc =  incantation_create(drone_tab[0], tile);
    setup_dummy_tile_resource(tile, RESOURCE_LINEMATE, 1);
    setup_dummy_tile_resource(tile, RESOURCE_DERAUMERE, 2);
    setup_dummy_tile_resource(tile, RESOURCE_SIBUR, 1);
    setup_dummy_tile_resource(tile, RESOURCE_MENDIANE, 3);
    cr_assert(incantation_check_requirements(inc) == false);
    clear_dummy_tile_drone(tile, drone_tab, drone_nb);
    tile_destroy(tile);
}

Test(incantation_check_requirements, not_enough_resources)
{
    tile_t *tile = tile_create();
    size_t drone_nb = 4;
    drone_t *drone_tab[drone_nb];
    incantation_t *inc = NULL;

    setup_dummy_tile_drone(tile, drone_tab, drone_nb, 5);
    inc =  incantation_create(drone_tab[0], tile);
    setup_dummy_tile_resource(tile, RESOURCE_LINEMATE, 1);
    setup_dummy_tile_resource(tile, RESOURCE_MENDIANE, 3);
    cr_assert(incantation_check_requirements(inc) == false);
    clear_dummy_tile_drone(tile, drone_tab, drone_nb);
    tile_destroy(tile);
}

Test(incantation_check_requirements, too_much_resources)
{
    tile_t *tile = tile_create();
    size_t drone_nb = 6;
    drone_t *drone_tab[drone_nb];
    incantation_t *inc = NULL;

    setup_dummy_tile_drone(tile, drone_tab, drone_nb, 7);
    inc =  incantation_create(drone_tab[0], tile);
    setup_dummy_tile_resource(tile, RESOURCE_LINEMATE, 2);
    setup_dummy_tile_resource(tile, RESOURCE_DERAUMERE, 2);
    setup_dummy_tile_resource(tile, RESOURCE_SIBUR, 2);
    setup_dummy_tile_resource(tile, RESOURCE_MENDIANE, 10);
    setup_dummy_tile_resource(tile, RESOURCE_PHIRAS, 2);
    setup_dummy_tile_resource(tile, RESOURCE_THYSTAME, 1);
    cr_assert(incantation_check_requirements(inc) == false);
    clear_dummy_tile_drone(tile, drone_tab, drone_nb);
    tile_destroy(tile);
}