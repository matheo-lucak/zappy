/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** drone
*/

#ifndef DRONE_H_
#define DRONE_H_

#include <stdbool.h>

#include "simulation/direction.h"
#include "simulation/inventory.h"

typedef struct map_s map_t;

typedef struct drone_s
{
    bool                   active;
    unsigned int                x;
    unsigned int                y;
    direction_t  facing_direction;
    inventory_t *       inventory;
    int             elevation_lvl;
} drone_t;

drone_t *drone_create(int x, int y);
void drone_destroy(drone_t *d);

bool drone_move(drone_t *drone, const map_t *map);
bool drone_rotate(drone_t *drone, direction_t direction);
bool drone_eject(drone_t *drone, const map_t *map, direction_t direction);

char *drone_get_look_format(const map_t *m, drone_t *d);
char *drone_get_look_format_down(const map_t *m, drone_t *d);
char *drone_get_look_format_left(const map_t *m, drone_t *d);
char *drone_get_look_format_right(const map_t *m, drone_t *d);
char *drone_get_look_format_up(const map_t *m, drone_t *d);

#endif /* !DRONE_H_ */
