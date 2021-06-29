/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** simulation_drone
*/

#ifndef ZAPPY_SIMULATION_DRONE_H_
#define ZAPPY_SIMULATION_DRONE_H_

#include <stdbool.h>

#define DRONE_DEFAULT_ELEVATION_LVL   1
#define DRONE_DEFAULT_FOOD_QUANTITY  10
#define DRONE_SATIETY_PER_FOOD      126

#include "simulation/direction.h"
#include "simulation/inventory.h"
#include "simulation/map.h"
#include "simulation/vector.h"

typedef struct drone_s
{
    bool                   active;
    vector2u_t                pos;
    int                   satiety;
    direction_t  facing_direction;
    inventory_t *       inventory;
    int             elevation_lvl;
} drone_t;

/**
* @brief Instantiates a newly allocated drone.
*
* @param position The position of the drone.
* @param activated Whether the drone is activated or not.
* @return drone_t*
*/
drone_t *drone_create(vector2u_t position, bool activated);

/**
* @brief Releases previously allocated memory to a drone.
*
* @param drone The drone to release memory from.
*/
void drone_destroy(drone_t *drone);

/**
* @brief Simulates hunger, eating and death.
*        Each call to drone_eat() reduces the satiety by 1 tick.
*        If the satiety reaches 0, the drone consumes 1 food
*        and restores its satiety.
*
* @param drone The drone to apply this function onto.
* @return true If the drone has any food or satiety left,
*              the drone lives.
* @return false If the drone has no more food and no more satiety,
*               the drone dies.
*/
bool drone_eat(drone_t *drone);

/**
* @brief Moves a drone forward on a map.
*
* @param drone The drone to move.
* @param map The map on which the drone is moved.
* @return true If the drone correctly moved.
* @return false If the drone didn't move.
*/
bool drone_move(drone_t *drone, const map_t *map);

/**
* @brief Rotates a drone by a direction.
*        Either LEFT or RIGHT works.
*
* @param drone The drone to rotate.
* @param direction The direction to rotate the drone.
* @return true If the drone managed to rotate in the given direction.
* @return false If the drone didn't managed to rotate in the given direction.
*/
bool drone_rotate(drone_t *drone, direction_t direction);

/**
* @brief Ejects a drone from its current tile on a map in a given direction.
*
* @param drone The drone to eject.
* @param map The map on which the drone is being ejected.
* @param direction The direction in which the drone is being ejected.
* @return true If the drone was ejected in the correct direction.
* @return false If the drone wasn't ejected in the correct direction.
*/
bool drone_eject(drone_t *drone, const map_t *map, direction_t direction);

/**
* @brief Gets the correct position of a drone
*        according to the map measurements.
*
* @param drone The drone to get the position of.
* @param map The map to get the position of the drone onto.
* @return vector2u_t The position on the map of the drone.
*/
vector2u_t drone_get_pos_on_map(drone_t *drone, const map_t *map);

/**
* @brief Gets the correct position of a drone, after a move,
*        according to the map measurements.
*
* @param drone The drone to get the position of.
* @param map The map to get the position of the drone onto.
* @param move The movement to add to the drone.
* @return vector2u_t The position on he map of the drone after the movement.
*/
vector2u_t drone_get_pos_after_move_on_map(drone_t *drone, const map_t *map,
                                            vector2i_t move);

/**
* @brief Gets the projection of the vision of the drone according to its
*        facing direction on a map.
*
* @param drone The drone to get the look format from.
* @param map The map on which the drone needs to return its look format.
* @return char* The newly allocated look format.
*/
char *drone_get_look_format(drone_t *drone, const map_t *map);

/**
* @brief Gets the map quarter in which a drone is located on a map.
*
* @param drone The drone to get the map quarter of.
* @param map The map.
* @return map_quarter_t The map quarter in which the drone is located.
*/
map_quarter_t drone_get_map_quarter(drone_t *drone, const map_t *map);

/**
* @brief Gets the 4 closest projections to where a sound can be emitted
*        on a torus map.
*
* @param base The position to which the sound will be emitted.
* @param proj An array of 4 vectors that will be filled
*             with the 4 computed projections.
* @param map The map from which the projections will be generated.
* @param quarter The quarter of the map to generate the projections from.
*/
void drone_get_sound_set_projections(vector2i_t base, vector2i_t proj[4],
                                    const map_t *map, map_quarter_t quarter);

/**
* @brief Gets the first tile on which the sound can be heard by a drone on
*        'projectile_tile'.
*
* @param drone The drone that emits the sound.
* @param projection_tile The projected tile on which the drone receiving
*                        the sound is.
* @return vector2i_t The first tile where the sound could be heard from
*                    a drone on 'projection_tile'.
*/
vector2i_t drone_get_sound_entering_tile(drone_t *drone,
                                        vector2i_t projection_tile);

/**
* @brief Gets the sound direction from a drone to another.
*
* @param drone_from The drone from which the sound is emitted.
* @param drone_to The drone the sound will reach.
* @param map The map on which the sound is emitted.
* @return local_direction_t The local_direction hit around the reached drone.
*/
local_direction_t drone_get_sound_direction(drone_t *drone_from,
                                            drone_t *drone_to,
                                            const map_t *map);

#endif /* !ZAPPY_SIMULATION_DRONE_H_ */
