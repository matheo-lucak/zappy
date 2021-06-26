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

#endif /* !MAP_H_ */
