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
    if (list_empty(inventory->slots))
        return NULL;
    list_foreach(node, inventory->slots) {
        if (NODE_PTR(node, item_slot_t)->type == type)
            return NODE_PTR(node, item_slot_t);
    }
    return NULL;
}
