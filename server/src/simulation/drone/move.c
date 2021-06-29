/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace) [WSL: Ubuntu]
** File description:
** move
*/

#include <stdbool.h>
#include "simulation/drone.h"
#include "simulation/map.h"

static bool drone_get_move(drone_t *drone, vector2i_t *move)
{
    switch (drone->facing_direction) {
        case UP:
            move->y = -1;
            break;
        case DOWN:
            move->y = 1;
            break;
        case LEFT:
            move->x = -1;
            break;
        case RIGHT:
            move->x = 1;
            break;
        default:
            return false;
    }
    return true;
}

bool drone_move(drone_t *drone, const map_t *map)
{
    vector2i_t move = VEC2I(0, 0);

    if (!drone_get_move(drone, &move))
        return false;
    drone->pos = drone_get_pos_after_move_on_map(map, drone, move);
    return true;
}
