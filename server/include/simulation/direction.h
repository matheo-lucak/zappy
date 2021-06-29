/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace) [WSL: Ubuntu]
** File description:
** direction
*/

#ifndef DIRECTION_H_
#define DIRECTION_H_

typedef enum direction_e
{
    UP,
    DOWN,
    LEFT,
    RIGHT
} direction_t;

typedef enum local_direction_e
{
    LCL_HERE = 0,
    LCL_UP = 1,
    LCL_UP_LEFT = 2,
    LCL_LEFT = 3,
    LCL_DOWN_LEFT = 4,
    LCL_DOWN = 5,
    LCL_DOWN_RIGHT = 6,
    LCL_RIGHT = 7,
    LCL_UP_RIGHT = 8,
} local_direction_t;

direction_t direction_get_random();
local_direction_t direction_get_eject_direction(direction_t facing_direction,
                                                direction_t pushed_direction);

#endif /* !DIRECTION_H_ */
