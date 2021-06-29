/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** simulation_direction
*/

#ifndef ZAPPY_SIMULATION_DIRECTION_H_
#define ZAPPY_SIMULATION_DIRECTION_H_

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

/**
* @brief Gets a random direction.
*
* @return direction_t The random direction obtained.
*/
direction_t direction_get_random(void);

/**
* @brief Gets the local_direction from which an ejection has occured.
*
* @param facing_direction The direction the ejected target was facing.
* @param pushed_direction The direction the ejector was pushing.
* @return local_direction_t The resultant.
*/
local_direction_t direction_get_eject_direction(direction_t facing_direction,
                                                direction_t pushed_direction);

#endif /* !ZAPPY_SIMULATION_DIRECTION_H_ */
