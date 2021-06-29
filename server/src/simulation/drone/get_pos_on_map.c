/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** get_pos_after_move_on_map
*/

#include "simulation/drone.h"

vector2u_t drone_get_pos_on_map(const map_t *map, drone_t *drone)
{
    vector2i_t future_pos = {drone->pos.x, drone->pos.y};

    future_pos.x %= (int)map->width;
    future_pos.y %= (int)map->height;
    while (future_pos.x < 0)
        future_pos.x += map->width;
    while (future_pos.y < 0)
        future_pos.y += map->height;
    return (vector2u_t){future_pos.x, future_pos.y};
}
