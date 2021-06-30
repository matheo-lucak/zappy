/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** get_map_quarter
*/

#include <stdbool.h>
#include "simulation/map.h"
#include "simulation/drone.h"

static bool is_drone_in_top_left(const map_t *map, drone_t *drone)
{
    unsigned int br_corner_x = map->width / 2 - !(map->width % 2);
    unsigned int br_corner_y = map->height / 2 - !(map->height % 2);

    return drone->pos.x <= br_corner_x && drone->pos.y <= br_corner_y;
}

static bool is_drone_in_top_right(const map_t *map, drone_t *drone)
{
    unsigned int tl_corner_x = map->width / 2 - !(map->width % 2);
    unsigned int tl_corner_y = 0;
    unsigned int br_corner_x = map->width - 1;
    unsigned int br_corner_y = map->height / 2 - !(map->height % 2);

    return drone->pos.x >= tl_corner_x && drone->pos.x <= br_corner_x
            && drone->pos.y >= tl_corner_y && drone->pos.y <= br_corner_y;
}

static bool is_drone_in_bottom_left(const map_t *map, drone_t *drone)
{
    unsigned int tl_corner_x = 0;
    unsigned int tl_corner_y = map->height / 2 - !(map->height % 2);
    unsigned int br_corner_x = map->width / 2 - !(map->width % 2);
    unsigned int br_corner_y = map->height - 1;

    return drone->pos.x >= tl_corner_x && drone->pos.x <= br_corner_x
            && drone->pos.y >= tl_corner_y && drone->pos.y <= br_corner_y;
}

map_quarter_t drone_get_map_quarter(drone_t *drone, const map_t *map)
{
    if (is_drone_in_top_left(map, drone))
        return MAP_TOP_LEFT;
    if (is_drone_in_top_right(map, drone))
        return MAP_TOP_RIGHT;
    if (is_drone_in_bottom_left(map, drone))
        return MAP_BOTTOM_LEFT;
    return MAP_BOTTOM_RIGHT;
}
