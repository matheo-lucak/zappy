/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** get_sound_entering_tile
*/

#include <stdlib.h>
#include <math.h>

#include "simulation/drone.h"

static bool is_pos_inside_listening_range(vector2i_t cur_pos, vector2i_t proj_tile)
{
    const double listening_range = sqrt(2);
    const double cur_range = vector2i_distance(cur_pos, proj_tile);

    return cur_range <= listening_range;
}

vector2i_t drone_get_sound_entering_tile(drone_t *d, vector2i_t proj_tile)
{
    vector2f_t cur_pos_f = VEC2F(0, 0);
    vector2i_t cur_pos_i = VEC2I(0, 0);
    vector2f_t dlt = VEC2F((float)proj_tile.x - (float)d->pos.x,
                            (float)proj_tile.y - (float)d->pos.y);
    const float step = fabs(dlt.x) >= fabs(dlt.y) ? fabs(dlt.x) : fabs(dlt.y);

    dlt.x /= step;
    dlt.y /= step;
    cur_pos_f.x = d->pos.x;
    cur_pos_f.y = d->pos.y;
    for (int i = 1; i <= step + 1; i++) {
        cur_pos_i = VEC2I((int)round(cur_pos_f.x), (int)round(cur_pos_f.y));
        if (is_pos_inside_listening_range(cur_pos_i, proj_tile))
            return cur_pos_i;
        cur_pos_f.x += dlt.x;
        cur_pos_f.y += dlt.y;
    }
    return VEC2I(d->pos.x, d->pos.y);
}
