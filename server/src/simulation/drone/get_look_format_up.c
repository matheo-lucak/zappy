/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** get_look_format_up
*/

#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <mylist.h>
#include <my.h>
#include "simulation/resources.h"
#include "simulation/drone.h"
#include "simulation/map.h"

static char *get_tile_look_format(const map_t *m,
                                unsigned int pos_x,
                                unsigned int pos_y)
{
    char *buffer = NULL;
    tile_t *tile = m->tiles[pos_y][pos_x];
    resource_type_t resource;
    const resource_info_t *resource_info = NULL;

    if (!list_empty(tile->drones))
        buffer = my_str_cat(buffer, "player", true, false);
    for (size_t i = 1; i < list_len(tile->drones); i++)
        buffer = my_str_cat(buffer, " player", true, false);
    if (!list_empty(tile->drones) && !list_empty(tile->items))
        buffer = my_str_cat(buffer, " ", true, false);
    if (!list_empty(tile->items)) {
        list_foreach(node, tile->items) {
            resource = NODE_DATA(node, resource_type_t);
            resource_info = resource_get_info_from_type(resource);
            buffer = my_str_cat(buffer, resource_info->name, true, false);
            if (node->next)
                buffer = my_str_cat(buffer, " ", true, false);
        }
    }
    return buffer;
}

static unsigned int get_pos_x(const map_t *m, drone_t *d, int x_move)
{
    int future_x_pos = 0;

    future_x_pos = d->x + x_move;
    future_x_pos = future_x_pos % (int)m->width;
    while (future_x_pos < 0)
        future_x_pos += m->width;
    return future_x_pos;
}

static unsigned int get_pos_y(const map_t *m, drone_t *d, int y_move)
{
    int future_y_pos = 0;

    future_y_pos = d->y + y_move;
    future_y_pos = future_y_pos % (int)m->height;
    while (future_y_pos < 0)
        future_y_pos += m->height;
    return future_y_pos;
}

char *drone_get_look_format_up(const map_t *m, drone_t *d)
{
    char *fmt = NULL;
    unsigned int x = 0;
    unsigned int y = 0;
    int x_off = 0;
    int y_off = 0;
    int x_off_max = 0;

    for (; x_off_max <= d->elevation_lvl; x_off_max++) {
        for (x_off = -x_off_max; x_off <= x_off_max; x_off++) {
            x = get_pos_x(m, d, x_off);
            y = get_pos_y(m, d, y_off);
            fmt = my_str_cat(fmt, get_tile_look_format(m, x, y), true, true);
            if (!(x_off_max == d->elevation_lvl && x_off == x_off_max))
                fmt = my_str_cat(fmt, ",", true, false);
        }
        y_off -= 1;
    }
    return fmt;
}
