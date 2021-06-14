/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace) [WSL: Ubuntu]
** File description:
** move
*/

#include "simulation/drone.h"
#include "simulation/direction.h"

static void drone_rotate_left(drone_t *drone)
{
    switch (drone->facing_direction) {
        case (UP):
            drone->facing_direction = LEFT;
            break;
        case (DOWN):
            drone->facing_direction = RIGHT;
            break;
        case (LEFT):
            drone->facing_direction = DOWN;
            break;
        case (RIGHT):
            drone->facing_direction = UP;
            break;
        default:
            break;
    }
}

static void drone_rotate_right(drone_t *drone)
{
    switch (drone->facing_direction) {
        case (UP):
            drone->facing_direction = RIGHT;
            break;
        case (DOWN):
            drone->facing_direction = LEFT;
            break;
        case (LEFT):
            drone->facing_direction = UP;
            break;
        case (RIGHT):
            drone->facing_direction = DOWN;
            break;
        default:
            break;
    }
}

int drone_rotate(drone_t *drone, direction_t direction)
{
    if (!drone)
        return 0;
    if (direction == LEFT)
        drone_rotate_left(drone);
    else if (direction == RIGHT)
        drone_rotate_right(drone);
    else
        return 0;
    return 1;
}
