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

typedef struct map_s map_t;

typedef struct drone_s
{
    bool                   active;
    unsigned int                x;
    unsigned int                y;
    int                   satiety;
    direction_t  facing_direction;
    inventory_t *       inventory;
    int             elevation_lvl;
} drone_t;

drone_t *drone_create(int x, int y, bool activated);
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

char *drone_get_look_format(const map_t *m, drone_t *d);
char *drone_get_look_format_down(const map_t *m, drone_t *d);
char *drone_get_look_format_left(const map_t *m, drone_t *d);
char *drone_get_look_format_right(const map_t *m, drone_t *d);
char *drone_get_look_format_up(const map_t *m, drone_t *d);

#endif /* !DRONE_H_ */
