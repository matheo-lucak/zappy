/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** add_item
*/

#include <criterion/criterion.h>
#include "simulation/inventory.h"

Test(inventory_add_item, simple_add_item)
{
    inventory_t *inventory = inventory_create();
    const item_slot_t *slot;

    cr_assert(inventory_get_item_info(inventory, RESOURCE_FOOD) == NULL);
    cr_assert(inventory_add_item(inventory, RESOURCE_FOOD, 10));
    slot = inventory_get_item_info(inventory, RESOURCE_FOOD);
    cr_assert(slot != NULL);
    cr_assert(slot->type == RESOURCE_FOOD);
    cr_assert(slot->quantity == 10);
    inventory_destroy(inventory);
}

Test(inventory_add_item, several_add_same_item)
{
    inventory_t *inventory = inventory_create();
    const item_slot_t *slot;

    cr_assert(inventory_get_item_info(inventory, RESOURCE_FOOD) == NULL);
    cr_assert(inventory_add_item(inventory, RESOURCE_FOOD, 10));
    slot = inventory_get_item_info(inventory, RESOURCE_FOOD);
    cr_assert(slot != NULL);
    cr_assert(slot->type == RESOURCE_FOOD);
    cr_assert(slot->quantity == 10);
    cr_assert(inventory_add_item(inventory, RESOURCE_FOOD, 15));
    slot = inventory_get_item_info(inventory, RESOURCE_FOOD);
    cr_assert(slot != NULL);
    cr_assert(slot->type == RESOURCE_FOOD);
    cr_assert(slot->quantity == 25);
    inventory_destroy(inventory);
}
