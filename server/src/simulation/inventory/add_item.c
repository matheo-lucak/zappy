/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** add_item
*/

#include <stdbool.h>
#include "simulation/inventory.h"

bool inventory_add_item(inventory_t *inventory,
                        resource_type_t type,
                        unsigned int quantity)
{
    item_slot_t *new_slot = NULL;

    list_foreach(node, inventory->slots) {
        if (NODE_PTR(node, item_slot_t)->type == type) {
            NODE_PTR(node, item_slot_t)->quantity += quantity;
            return true;
        }
    }
    new_slot = generic_list_emplace_back(inventory->slots, item_slot_t);
    if (!new_slot)
        return false;
    new_slot->type = type;
    new_slot->quantity = quantity;
    return true;
}
