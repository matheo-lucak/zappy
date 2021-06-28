/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include "simulation/tile.h"

#define MAP_TIME_TO_REFILL 20

typedef int resource_quantity_t;

typedef resource_quantity_t resource_quantities_t[RESOURCE_NB];

typedef struct map_s
{
    unsigned int            width;
    unsigned int            height;
    tile_t ***              tiles;
    resource_quantities_t   expected;
    int                     time_until_refill;
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
 * @brief Refill the map of resources each MAP_TIME_TO_REFILL call
 *
 * @param map The map.
 * @return true if the map has been refilled
 */
bool map_refill(map_t *map);

void map_count_resources(map_t *map, resource_quantities_t *count);
void map_clear_resources(map_t *map);

#endif /* !MAP_H_ */
