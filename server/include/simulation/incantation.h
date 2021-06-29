/*
** EPITECH PROJECT, 2021
** server
** File description:
** incantation
*/

#ifndef INCANTATION_H_
#define INCANTATION_H_

#include <stddef.h>

#include "simulation/tile.h"
#include "simulation/drone.h"
#include "simulation/resources.h"

#define ELEVATION_MAX_LVL               8
#define INCANTATION_TIME_TO_ELEVATE     300

typedef struct elevation_requirement_s
{
    size_t  drone_nb;
    int     drone_lvl;
    size_t  resources[RESOURCE_NB];
} elevation_requirement_t;

typedef struct incantation_s
{
    const elevation_requirement_t * requirements;
    int                             time_until_elevation;
    int                             elevation_lvl;
    drone_t *                       owner;
    tile_t *                        tile;
} incantation_t;

/**
* @brief Creates an incantation.
*
* Computes requirements based on the owner elevation level.
*
* @param owner The drone that started the incantation.
* @param tile The tile where the incantation has started on.
* @return response_t* A pointer to the newly allocated incantation.
*/
incantation_t *incantation_create(drone_t *owner, tile_t *tile);

/**
* @brief Releases memory previously allocated to a incantation.
*
* @param incantation The incantation to release memory from.
*/
void incantation_destroy(incantation_t *incantation);

/**
* @brief Checks if the exact requirements are matched on the incantation tile.
*
* Three things are checked:
* - The number of players on the tile.
* - The level of each player on the tile.
* - The type and the amount of each ressources on the tile (food doesn't count).
*
* @param incantation The incantation to check.
* @return bool If the requirements are exactly matched.
*/
bool incantation_check_requirements(incantation_t *inc);

/**
* @brief Simulates an elevation
*
* This must be call after a successfull call of incantation_check_requirements.
*
* All player on the tile gets one level.
* All required resources are consumed from the tile.
*
* @param incantation The incantation to end.
*/
void incantation_elevate(incantation_t *inc);

/**
* @brief Removes the incantation owner
*
* @param incantation The incantation to remove owner.
*/
void incantation_remove_owner(incantation_t *incantation);

const elevation_requirement_t *incantation_find_requirements(int drone_lvl);

extern const elevation_requirement_t elevation_requirements[];
extern const size_t elevation_requirements_size;

#endif /* !INCANTATION_H_ */
