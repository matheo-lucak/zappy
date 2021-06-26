/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace) [WSL: Ubuntu]
** File description:
** move
*/

#include <stdbool.h>
#include "simulation/drone.h"
#include "simulation/map.h"

static bool drone_get_move(drone_t *drone, int *x, int *y)
{
    switch (drone->facing_direction) {
        case UP:
            *y = -1;
            break;
        case DOWN:
            *y = 1;
            break;
        case LEFT:
            *x = -1;
            break;
        case RIGHT:
            *x = 1;
            break;
        default:
            return false;
    }
    return true;
}

static void drone_apply_move(drone_t *drone, int x_move, int y_move, const map_t *map)
{
    int future_x_pos = 0;
    int future_y_pos = 0;

    future_x_pos = drone->x + x_move;
    future_x_pos = future_x_pos % (int)map->width;
    while (future_x_pos < 0)
        future_x_pos += map->width;
    future_y_pos = drone->y + y_move;
    future_y_pos = future_y_pos % (int)map->height;
    while (future_y_pos < 0)
        future_y_pos += map->height;
    drone->x = future_x_pos;
    drone->y = future_y_pos;
}

bool drone_move(drone_t *drone, const map_t *map)
{
    int x_move = 0;
    int y_move = 0;

    if (!drone_get_move(drone, &x_move, &y_move))
        return false;
    drone_apply_move(drone, x_move, y_move, map);
    return true;
}
