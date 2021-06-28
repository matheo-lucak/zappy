/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** drone
*/

#ifndef DRONE_H_
#define DRONE_H_

#include <stdbool.h>

#define DRONE_DEFAULT_ELEVATION_LVL 1
#define DRONE_DEFAULT_FOOD_QUANTITY 10
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

drone_t *drone_create(vector2u_t position, bool activated);
void drone_destroy(drone_t *d);


////////////////////////////////////////////////////////////////////////////////
/// \brief Simulates hunger, eats food and die
///
/// Each call of drone_eat reduces the satiety by 1 tick
///
/// If the satiety reach 0, the drone consumes 1 food
/// and restores its satiety
///
/// If the drone has no more food and no more satiety,
/// the drone dies and the functions returns false
///
/// In any other cases, the drone is still alive and it returns true
////////////////////////////////////////////////////////////////////////////////
bool drone_eat(drone_t *drone);

bool drone_move(drone_t *drone, const map_t *map);
bool drone_rotate(drone_t *drone, direction_t direction);
bool drone_eject(drone_t *drone, const map_t *map, direction_t direction);

vector2u_t drone_get_pos_on_map(const map_t *map, drone_t *drone);
vector2u_t drone_get_pos_after_move_on_map(const map_t *map,
                                            drone_t *drone,
                                            vector2i_t move);

char *drone_get_look_format(const map_t *map, drone_t *drone);

map_quarter_t drone_get_map_quarter(const map_t *map, drone_t *drone);

#endif /* !DRONE_H_ */
