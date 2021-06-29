/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** remove_item
*/

#include <criterion/criterion.h>
#include "simulation/resources.h"
#include "simulation/tile.h"

Test(tile_remove_item, simple_remove_item)
{
    tile_t *tile = tile_create();

    cr_assert(!generic_list_find(tile->items,
                                RESOURCE_THYSTAME,
                                resource_type_t));
    cr_assert(tile_add_item(tile, RESOURCE_THYSTAME));
    cr_assert(generic_list_find(tile->items,
                                RESOURCE_THYSTAME,
                                resource_type_t));
    cr_assert(tile_remove_item(tile, RESOURCE_THYSTAME));
    cr_assert(!generic_list_find(tile->items,
                                RESOURCE_THYSTAME,
                                resource_type_t));
    tile_destroy(tile);
}

Test(tile_remove_item, several_remove_same_item)
{
    tile_t *tile = tile_create();

    cr_assert(!generic_list_find(tile->items,
                RESOURCE_THYSTAME, resource_type_t));
    cr_assert(tile_add_item(tile, RESOURCE_THYSTAME));
    cr_assert(generic_list_find(tile->items,
                RESOURCE_THYSTAME, resource_type_t));
    cr_assert(tile_add_item(tile, RESOURCE_THYSTAME));
    cr_assert(generic_list_find(tile->items,
                RESOURCE_THYSTAME, resource_type_t));
    cr_assert(tile_remove_item(tile, RESOURCE_THYSTAME));
    cr_assert(generic_list_find(tile->items,
                RESOURCE_THYSTAME, resource_type_t));
    cr_assert(tile_remove_item(tile, RESOURCE_THYSTAME));
    cr_assert(!generic_list_find(tile->items,
                RESOURCE_THYSTAME, resource_type_t));
    tile_destroy(tile);
}
