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

#endif /* !TILE_H_ */
