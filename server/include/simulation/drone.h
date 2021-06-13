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

typedef struct drone_s
{
    unsigned int                x;
    unsigned int                y;
    direction_t  facing_direction;
    inventory_t         inventory;
} drone_t;

drone_t *drone_create(int x, int y);
void drone_destroy(drone_t *d);

#endif /* !DRONE_H_ */
