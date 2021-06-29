/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include "simulation/tile.h"
#include "simulation/vector.h"

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

typedef enum map_quarter_e
{
    MAP_TOP_LEFT,
    MAP_TOP_RIGHT,
    MAP_BOTTOM_LEFT,
    MAP_BOTTOM_RIGHT
} map_quarter_t;

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


bool map_add_drone(map_t *map, drone_t *drone);

char *map_get_tile_look_format(const map_t *map, vector2u_t pos);

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
