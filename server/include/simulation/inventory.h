/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** simulation_inventory
*/

#ifndef ZAPPY_SIMULATION_INVENTORY_H_
#define ZAPPY_SIMULATION_INVENTORY_H_

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

/**
* @brief Instantes a newly allocated inventory.
*
* @return inventory_t* The newly allocated inventory.
*/
inventory_t *inventory_create(void);

/**
* @brief Releases memory from a previously allocated inventory.
*
* @param inventory The inventory to release memory from.
*/
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
bool inventory_add_item(inventory_t *inventory, resource_type_t type,
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

/**
* @brief Gets the amount of RESOURCE_FOOD held in an inventory.
*
* @param inventory The inventory from which to retrieve
*                  the amount of RESOURCE_FOOD held.
* @return unsigned int The amount of RESOURCE_FOOD held in the inventory.
*/
unsigned int inventory_get_food_info(inventory_t *inventory);

/**
* @brief Gets the amount of RESOURCE_LINEMATE held in an inventory.
*
* @param inventory The inventory from which to retrieve
*                  the amount of RESOURCE_LINEMATE held.
* @return unsigned int The amount of RESOURCE_LINEMATE held in the inventory.
*/
unsigned int inventory_get_linemate_info(inventory_t *inventory);

/**
* @brief Gets the amount of RESOURCE_DERAUMERE held in an inventory.
*
* @param inventory The inventory from which to retrieve
*                  the amount of RESOURCE_DERAUMERE held.
* @return unsigned int The amount of RESOURCE_DERAUMERE held in the inventory.
*/
unsigned int inventory_get_deraumere_info(inventory_t *inventory);

/**
* @brief Gets the amount of RESOURCE_SIBUR held in an inventory.
*
* @param inventory The inventory from which to retrieve
*                  the amount of RESOURCE_SIBUR held.
* @return unsigned int The amount of RESOURCE_SIBUR held in the inventory.
*/
unsigned int inventory_get_sibur_info(inventory_t *inventory);

/**
* @brief Gets the amount of RESOURCE_MENDIANE held in an inventory.
*
* @param inventory The inventory from which to retrieve
*                  the amount of RESOURCE_MENDIANE held.
* @return unsigned int The amount of RESOURCE_MENDIANE held in the inventory.
*/
unsigned int inventory_get_mendiane_info(inventory_t *inventory);

/**
* @brief Gets the amount of RESOURCE_PHIRAS held in an inventory.
*
* @param inventory The inventory from which to retrieve
*                  the amount of RESOURCE_PHIRAS held.
* @return unsigned int The amount of RESOURCE_PHIRAS held in the inventory.
*/
unsigned int inventory_get_phiras_info(inventory_t *inventory);

/**
* @brief Gets the amount of RESOURCE_THYSTAME held in an inventory.
*
* @param inventory The inventory from which to retrieve
*                  the amount of RESOURCE_THYSTAME held.
* @return unsigned int The amount of RESOURCE_THYSTAME held in the inventory.
*/
unsigned int inventory_get_thystame_info(inventory_t *inventory);

#endif /* !ZAPPY_SIMULATION_INVENTORY_H_ */
