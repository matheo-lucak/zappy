/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** create
*/

#include <stdlib.h>
#include "simulation/inventory.h"

inventory_t *inventory_create(void)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    inventory->slots = generic_list_create(&free);
    return inventory;
}
