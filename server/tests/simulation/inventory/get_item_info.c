/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** get_item_info
*/

#include <criterion/criterion.h>
#include "simulation/inventory.h"

Test(inventory_get_item_info, simple_get_info)
{
    inventory_t *inventory = inventory_create();
    const item_slot_t *slot;

    cr_assert(inventory_add_item(inventory, RESOURCE_FOOD, 14));
    cr_assert(inventory_add_item(inventory, RESOURCE_LINEMATE, 2));
    cr_assert(inventory_add_item(inventory, RESOURCE_THYSTAME, 20));
    slot = inventory_get_item_info(inventory, RESOURCE_LINEMATE);
    cr_assert(slot != NULL);
    cr_assert(slot->type == RESOURCE_LINEMATE);
    cr_assert(slot->quantity == 2);
    inventory_destroy(inventory);
}

Test(inventory_get_item_info, simple_cant_find_info)
{
    inventory_t *inventory = inventory_create();
    const item_slot_t *slot;

    cr_assert(inventory_add_item(inventory, RESOURCE_FOOD, 14));
    cr_assert(inventory_add_item(inventory, RESOURCE_LINEMATE, 2));
    cr_assert(inventory_add_item(inventory, RESOURCE_THYSTAME, 20));
    slot = inventory_get_item_info(inventory, RESOURCE_MENDIANE);
    cr_assert(slot == NULL);
    inventory_destroy(inventory);
}
