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
 * @brief Removes an item and a quantity associated with from an inventory.
 * 
 * @param inventory The inventory concerned.
 * @param type The type of item to remove.
 * @param quantity The quantity to remove of the item type.
 * @return true If the remove occured.
 * @return false If it didn't.
 */
bool inventory_remove_item(inventory_t *inventory,
                            resource_type_t type,
                            unsigned int quantity);

/**
 * @brief Gets an item slot information from an inventory.
 * 
 * @param inventory The inventory concerned.
 * @param type The type of item to get information on.
 * @return const item_slot_t* The pointer of the node.
 */
const item_slot_t *inventory_get_item_info(inventory_t *inventory,
                                            resource_type_t type);

#endif /* !INVENTORY_H_ */
