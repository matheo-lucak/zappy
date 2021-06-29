/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** tile
*/

#ifndef TILE_H_
#define TILE_H_

#include <stdbool.h>
#include <mylist.h>
#include "simulation/resources.h"

typedef struct drone_s drone_t;

typedef struct tile_s
{
    ptr_list_t *drones;
    list_t *items;
} tile_t;

/**
* @brief Allocates memory for a new tile.
*
* @return tile_t* The newly allocated tile.
*/
tile_t *tile_create(void);

/**
* @brief Releases memory previously allocated to a map.
*
* @param tile The tile on which memory needs to be released.
*/
void tile_destroy(tile_t *tile);

/**
* @brief Adds a drone to a given tile.
*
* @param tile The tile to add the drone onto.
* @param drone The drone to add to the tile.
* @return true If the drone has correctly been added to the tile.
* @return false If the drone already is on the tile or hasn't been added.
*/
bool tile_add_drone(tile_t *tile, drone_t *drone);

/**
* @brief Removes a drone on a given tile.
*
* @param tile The tile to remove the drone onto.
* @param drone The drone to remove of the tile.
* @return true If the drone has correctly been removed of the tile.
* @return false If the drone wasn't on the tile or hasn't been removed.
*/
bool tile_remove_drone(tile_t *tile, drone_t *drone);

/**
* @brief Counts the number of drones on the tile.
*
* @param tile The tile to search into.
* @return The number drones in the tile
*/
size_t tile_count_drone(tile_t *tile);

/**
* @brief Adds an item on a given tile.
*
* @param tile The tile to add the item onto.
* @param type The type of item to add.
* @return true If the item has correctly been added on the tile.
* @return false If the item wasn't correctly added on the tile.
*/
bool tile_add_item(tile_t *tile, resource_type_t type);

/**
* @brief Removes an item on a given tile.
*
* @param tile The tile to remove the item onto.
* @param type The type of item to remove.
* @return true If the item has correctly been removed from the tile.
* @return false If the item wasn't correctly removed from the tile.
*/
bool tile_remove_item(tile_t *tile, resource_type_t type);

/**
* @brief Removes an item on a given tile.
*
* @param tile The tile to search into.
* @param type The type of item to count.
* @return The number of ressources matching the given type
*/
size_t tile_count_item(tile_t *tile, resource_type_t type);


/**
* @brief Removes all items from the tile.
*
* @param tile The tile to clear.
*/
void tile_clear_items(tile_t *tile);

/**
* @brief Checks whether the tile has drones on it.
*
* @param tile The tile to check.
* @return true If the tile has at least one.
* @return false If it has none.
*/
bool tile_has_drones(tile_t *tile);

/**
* @brief Checks whether the tile has items on it.
*
* @param tile The tile to check.
* @return true If the tile has at least one.
* @return false If it has none.
*/
bool tile_has_items(tile_t *tile);

/**
* @brief Checks whether the tile has nothing on it.
*
* @param tile The tile to check.
* @return true If it has none.
* @return false If the tile has at least one drone/object on it.
*/
bool tile_is_empty(tile_t *tile);

#endif /* !TILE_H_ */
