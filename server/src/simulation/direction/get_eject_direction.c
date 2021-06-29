/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** get_eject_direction
*/

#include "simulation/direction.h"

static local_direction_t get_direction_right(direction_t facing_direction,
                                            direction_t pushed_direction)
{
    if (pushed_direction == RIGHT) {
        if (facing_direction == UP)
            return LCL_LEFT;
        if (facing_direction == DOWN)
            return LCL_RIGHT;
        if (facing_direction == LEFT)
            return LCL_UP;
        if (facing_direction == RIGHT)
            return LCL_DOWN;
    }
    return LCL_HERE;
}

static local_direction_t get_direction_left(direction_t facing_direction,
                                            direction_t pushed_direction)
{
    if (pushed_direction == LEFT) {
        if (facing_direction == UP)
            return LCL_RIGHT;
        if (facing_direction == DOWN)
            return LCL_LEFT;
        if (facing_direction == LEFT)
            return LCL_DOWN;
        if (facing_direction == RIGHT)
            return LCL_UP;
    }
    return LCL_HERE;
}

static local_direction_t get_direction_down(direction_t facing_direction,
                                            direction_t pushed_direction)
{
    if (pushed_direction == DOWN) {
        if (facing_direction == UP)
            return LCL_UP;
        if (facing_direction == DOWN)
            return LCL_DOWN;
        if (facing_direction == LEFT)
            return LCL_RIGHT;
        if (facing_direction == RIGHT)
            return LCL_LEFT;
    }
    return LCL_HERE;
}

static local_direction_t get_direction_up(direction_t facing_direction,
                                        direction_t pushed_direction)
{
    if (pushed_direction == UP) {
        if (facing_direction == UP)
            return LCL_DOWN;
        if (facing_direction == DOWN)
            return LCL_UP;
        if (facing_direction == LEFT)
            return LCL_LEFT;
        if (facing_direction == RIGHT)
            return LCL_RIGHT;
    }
    return LCL_HERE;
}

local_direction_t direction_get_eject_direction(direction_t facing_direction,
                                                direction_t pushed_direction)
{
    local_direction_t direction = LCL_HERE;

    direction = get_direction_up(facing_direction, pushed_direction);
    if (direction != LCL_HERE)
        return direction;
    direction = get_direction_down(facing_direction, pushed_direction);
    if (direction != LCL_HERE)
        return direction;
    direction = get_direction_left(facing_direction, pushed_direction);
    if (direction != LCL_HERE)
        return direction;
    direction = get_direction_right(facing_direction, pushed_direction);
    if (direction != LCL_HERE)
        return direction;
    return LCL_HERE;
}
