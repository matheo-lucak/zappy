/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** add_item
*/

#include <stdbool.h>
#include "simulation/inventory.h"

bool inventory_remove_item(inventory_t *inventory,
                            resource_type_t type,
                            unsigned int quantity)
{
    int index = 0;

    if (list_empty(inventory->slots))
        return false;
    list_foreach(node, inventory->slots) {
        if (NODE_PTR(node, item_slot_t)->type == type) {
            if (NODE_PTR(node, item_slot_t)->quantity <= quantity) {
                list_pop(inventory->slots, index);
            } else
                NODE_PTR(node, item_slot_t)->quantity -= quantity;
            return true;
        }
        index += 1;
    }
    return false;
}
