/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** get_sibur_info
*/

#include "simulation/inventory.h"
#include "simulation/resources.h"

unsigned int inventory_get_mendiane_amount(inventory_t *inventory)
{
    const item_slot_t *slot = inventory_get_item_info(inventory,
                                                    RESOURCE_MENDIANE);

    if (!slot)
        return 0;
    return slot->quantity;
}
