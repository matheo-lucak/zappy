/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** inventory
*/

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <stdbool.h>
#include <mylist.h>
#include "simulation/resources.h"

typedef struct item_slot_s
{
    resource_type_t type;
    unsigned int quantity;
} item_slot_t;

typedef struct inventory_s
{
    list_t *slots;
} inventory_t;

inventory_t *inventory_create(void);
void inventory_destroy(inventory_t *inventory);

/**
* @brief Adds an item to an inventory. If the item already
*        is in the inventory, it adds the given quantity
*        to the existing stack. Otherwise, it adds it
*        with the given quantity.
* 
* @param inventory The iventory in which the item is added.
* @param type The type of item to be added.
* @param quantity The quantity to add to the item.
* @return true If the item was correctly added.
* @return false If the item wasn't added.
*/
bool inventory_add_item(inventory_t *inventory,
                        resource_type_t type,
                        unsigned int quantity);

/**
 * @brief 
 * 
 * @param inventory 
 * @param type 
 * @param quantity 
 * @return true 
 * @return false 
 */
bool inventory_remove_item(inventory_t *inventory,
                            resource_type_t type,
                            unsigned int quantity);

const item_slot_t *inventory_get_item_info(inventory_t *inventory,
                                            resource_type_t type);

#endif /* !INVENTORY_H_ */
