/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** get_look_format_up
*/

#include <my.h>
#include "simulation/drone.h"
#include "simulation/vector.h"

static bool is_last_tile_in_sight(drone_t *d, vector2i_t off,
                                vector2i_t off_max)
{
    switch (d->facing_direction) {
        case LEFT:
            return off_max.y == d->elevation_lvl && off.y == -off_max.y;
        case RIGHT:
            return off_max.y == d->elevation_lvl && off.y == off_max.y;
        case UP:
            return off_max.x == d->elevation_lvl && off.x == off_max.x;
        case DOWN:
            return off_max.x == d->elevation_lvl && off.x == -off_max.x;
        default:
            break;
    }
    return true;
}

static bool go_to_next_line_of_sight(drone_t *d, vector2i_t *off,
                                    vector2i_t *off_max)
{
    if (d->facing_direction == UP || d->facing_direction == DOWN) {
        off->y += d->facing_direction == DOWN ? 1 : -1;
        off_max->x += 1;
        return off_max->x <= d->elevation_lvl;
    }
    off->x += d->facing_direction == RIGHT ? 1 : -1;
    off_max->y += 1;
    return off_max->y <= d->elevation_lvl;
}

static void set_offset_by_direction(drone_t *d,
                                    vector2i_t *off,
                                    vector2i_t off_max)
{
    switch (d->facing_direction) {
        case UP:
            off->x = -off_max.x;
            return;
        case DOWN:
            off->x = off_max.x;
            return;
        case LEFT:
            off->y = off_max.y;
            return;
        case RIGHT:
            off->y = -off_max.y;
            return;
        default:
            break;
    }
}

static bool go_to_next_tile_in_line_of_sight(drone_t *d,
                                            vector2i_t *off,
                                            vector2i_t off_max)
{
    switch (d->facing_direction) {
        case UP:
            off->x += 1;
            return off->x <= off_max.x;
        case DOWN:
            off->x -= 1;
            return off->x >= -off_max.x;
        case LEFT:
            off->y -= 1;
            return off->y >= -off_max.y;
        case RIGHT:
            off->y += 1;
            return off->y <= off_max.y;
        default:
            break;
    }
    return false;
}

char *drone_get_look_format(drone_t *d, const map_t *m)
{
    char *fmt = NULL;
    vector2u_t pos = {0, 0};
    vector2i_t off = {0, 0};
    vector2i_t off_max = {0, 0};

    do {
        set_offset_by_direction(d, &off, off_max);
        do {
            pos = drone_get_pos_after_move_on_map(d, m, off);
            if (fmt && !tile_is_empty(m->tiles[pos.y][pos.x]))
                fmt = my_str_cat(fmt, " ", true, false);
            fmt = my_str_cat(fmt, map_get_tile_look_format(m, pos), true, true);
            if (!is_last_tile_in_sight(d, off, off_max))
                fmt = my_str_cat(fmt, ",", true, false);
        } while (go_to_next_tile_in_line_of_sight(d, &off, off_max));
    } while (go_to_next_line_of_sight(d, &off, &off_max));
    return fmt;
}
