/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** drone
*/

#ifndef DRONE_H_
#define DRONE_H_

#include "simulation/direction.h"
#include "simulation/inventory.h"
#include "simulation/map.h"

typedef struct drone_s
{
    unsigned int                x;
    unsigned int                y;
    direction_t  facing_direction;
    inventory_t         inventory;
} drone_t;

drone_t *drone_create(int x, int y);
void drone_destroy(drone_t *d);

int drone_move(drone_t *drone, const map_t *map);
int drone_rotate(drone_t *drone, direction_t direction);

#endif /* !DRONE_H_ */
