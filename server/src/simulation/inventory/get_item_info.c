/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** add_item
*/

#include <stdbool.h>
#include "simulation/inventory.h"

const item_slot_t *inventory_get_item_info(inventory_t *inventory,
                                            resource_type_t type)
{
    item_slot_t *slot = NULL;

    list_foreach(node, inventory->slots) {
        if (NODE_PTR(node, item_slot_t)->type == type) {
            slot = NODE_PTR(node, item_slot_t);
            node_iter_end(&node);
            return slot;
        }
    }
    return NULL;
}
