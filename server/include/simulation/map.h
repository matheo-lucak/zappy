/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** simulation_map
*/

#ifndef ZAPPY_SIMULATION_MAP_H_
#define ZAPPY_SIMULATION_MAP_H_

#include "simulation/tile.h"
#include "simulation/vector.h"

#define MAP_TIME_TO_REFILL 20

typedef int resource_quantity_t;

typedef resource_quantity_t resource_quantities_t[RESOURCE_NB];

typedef struct map_s
{
    unsigned int          width;
    unsigned int          height;
    tile_t ***            tiles;
    resource_quantities_t expected;
    int                   time_until_refill;
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

/**
* @brief At a given tile position, gets a look formatted string of
*        the drones and items located on the tile.
*
* @param map The map to find the tile on.
* @param pos The position of the tile on the map.
* @return char* The newly allocated look formatted string.
*/
char *map_get_tile_look_format(const map_t *map, vector2u_t pos);

/**
* @brief Refill the map of resources each MAP_TIME_TO_REFILL call.
*
* @param map The map.
* @return true if the map has been refilled.
*/
bool map_refill(map_t *map);

/**
* @brief Clears all resources from the map.
*
* @param map The map to remove resources.
*/

void map_clear_resources(map_t *map);

void map_count_resources(map_t *map, resource_quantities_t *count);

#endif /* !ZAPPY_SIMULATION_MAP_H_ */
