/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** get_look_format
*/

#include "simulation/map.h"
#include "simulation/drone.h"

char *drone_get_look_format(const map_t *m, drone_t *d)
{
    if (!d)
        return NULL;
    switch (d->facing_direction) {
        case LEFT:
            return drone_get_look_format_left(m, d);
        case RIGHT:
            return drone_get_look_format_right(m, d);
        case UP:
            return drone_get_look_format_up(m, d);
        case DOWN:
            return drone_get_look_format_down(m, d);
        default:
            break;
    }
    return NULL;
}
