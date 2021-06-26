/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include "simulation/tile.h"

typedef struct map_s
{
    unsigned int width;
    unsigned int height;
    tile_t ***tiles;
} map_t;

/**
 * @brief Allocates memory for a new map.
 * 
 * @param width The width of the map.
 * @param height The height of the map.
 * @return map_t* The newly allocated map.
 */
map_t *map_create(unsigned int width, unsigned int height);

/**
 * @brief Releases memory previously allocated to a map.
 * 
 * @param map The map on which memory needs to be released.
 */
void map_destroy(map_t *map);

/**
 * @brief Gets tile information from a map. (Complexity: O0).
 * 
 * @param map The map to look onto.
 * @param pos_x Position on X for the searched tile.
 * @param pos_y Position on Y for the searched tile.
 * @return const tile_t* The searched tile.
 */
const tile_t *map_get_tile_info(const map_t *map, unsigned int pos_x, unsigned int pos_y);

#endif /* !MAP_H_ */
