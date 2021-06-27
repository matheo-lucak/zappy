/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** remove_item
*/

#include <criterion/criterion.h>
#include "simulation/inventory.h"

Test(inventory_remove_item, simple_remove_item_completely)
{
    inventory_t *inventory = inventory_create();

    cr_assert(inventory_add_item(inventory, RESOURCE_FOOD, 10));
    cr_assert(inventory_get_item_info(inventory, RESOURCE_FOOD) != NULL);
    cr_assert(inventory_remove_item(inventory, RESOURCE_FOOD, 10));
    cr_assert(inventory_get_item_info(inventory, RESOURCE_FOOD) == NULL);
    inventory_destroy(inventory);
}

Test(inventory_remove_item, simple_remove_item_partial)
{
    inventory_t *inventory = inventory_create();
    const item_slot_t *slot;

    cr_assert(inventory_add_item(inventory, RESOURCE_FOOD, 10));
    cr_assert(inventory_get_item_info(inventory, RESOURCE_FOOD) != NULL);
    cr_assert(inventory_remove_item(inventory, RESOURCE_FOOD, 5));
    slot = inventory_get_item_info(inventory, RESOURCE_FOOD);
    cr_assert(slot != NULL);
    cr_assert(slot->type == RESOURCE_FOOD);
    cr_assert(slot->quantity == 5);
    inventory_destroy(inventory);
}
