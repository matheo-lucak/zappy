/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** add_item
*/

#include <criterion/criterion.h>
#include "simulation/resources.h"
#include "simulation/tile.h"

Test(tile_count_item, empty_tile)
{
    tile_t *tile = tile_create();

    cr_assert(tile_count_item(tile, RESOURCE_FOOD) == 0);
    cr_assert(tile_count_item(tile, RESOURCE_LINEMATE) == 0);
    cr_assert(tile_count_item(tile, RESOURCE_DERAUMERE) == 0);
    cr_assert(tile_count_item(tile, RESOURCE_SIBUR) == 0);
    cr_assert(tile_count_item(tile, RESOURCE_MENDIANE) == 0);
    cr_assert(tile_count_item(tile, RESOURCE_PHIRAS) == 0);
    cr_assert(tile_count_item(tile, RESOURCE_THYSTAME) == 0);
    tile_destroy(tile);
}

Test(tile_count_item, few_same_items_on_tile)
{
    tile_t *tile = tile_create();

    cr_assert(tile_add_item(tile, RESOURCE_DERAUMERE));
    cr_assert(tile_add_item(tile, RESOURCE_DERAUMERE));
    cr_assert(tile_add_item(tile, RESOURCE_DERAUMERE));
    cr_assert(tile_count_item(tile, RESOURCE_FOOD) == 0);
    cr_assert(tile_count_item(tile, RESOURCE_LINEMATE) == 0);
    cr_assert(tile_count_item(tile, RESOURCE_DERAUMERE) == 3);
    cr_assert(tile_count_item(tile, RESOURCE_SIBUR) == 0);
    cr_assert(tile_count_item(tile, RESOURCE_MENDIANE) == 0);
    cr_assert(tile_count_item(tile, RESOURCE_PHIRAS) == 0);
    cr_assert(tile_count_item(tile, RESOURCE_THYSTAME) == 0);
    tile_destroy(tile);
}

Test(tile_count_item, few_different_items_on_tile)
{
    tile_t *tile = tile_create();

    cr_assert(tile_add_item(tile, RESOURCE_PHIRAS));
    cr_assert(tile_add_item(tile, RESOURCE_LINEMATE));
    cr_assert(tile_add_item(tile, RESOURCE_PHIRAS));
    cr_assert(tile_add_item(tile, RESOURCE_DERAUMERE));
    cr_assert(tile_add_item(tile, RESOURCE_SIBUR));
    cr_assert(tile_count_item(tile, RESOURCE_FOOD) == 0);
    cr_assert(tile_count_item(tile, RESOURCE_LINEMATE) == 1);
    cr_assert(tile_count_item(tile, RESOURCE_DERAUMERE) == 1);
    cr_assert(tile_count_item(tile, RESOURCE_SIBUR) == 1);
    cr_assert(tile_count_item(tile, RESOURCE_MENDIANE) == 0);
    cr_assert(tile_count_item(tile, RESOURCE_PHIRAS) == 2);
    cr_assert(tile_count_item(tile, RESOURCE_THYSTAME) == 0);
    tile_destroy(tile);
}