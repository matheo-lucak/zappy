/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** destroy
*/

#include <stdlib.h>
#include "simulation/inventory.h"

void inventory_destroy(inventory_t *inventory)
{
    if (!inventory)
        return;
    generic_list_destroy(inventory->slots);
    free(inventory);
}
