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
    list_foreach(it, inventory->slots) {
        if (NODE_PTR(it, item_slot_t)->type == type) {
            if (NODE_PTR(it, item_slot_t)->quantity <= quantity) {
                list_pop(inventory->slots, it->index);
            } else {
                NODE_PTR(it, item_slot_t)->quantity -= quantity;
            }
            node_iter_end(&it);
            return true;
        }
    }
    return false;
}
