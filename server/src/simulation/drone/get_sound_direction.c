/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** get_sound_best_wall
*/

#include <float.h>
#include <math.h>

#include "simulation/direction.h"
#include "simulation/map.h"
#include "simulation/drone.h"

static vector2i_t find_best_projection(vector2i_t base,
                                        vector2i_t *projections)
{
    vector2i_t proj = {0};
    double best_distance = DBL_MAX;
    double distance = 0;

    for (int i = 0; i < 4; i++) {
        distance = vector2i_distance(base, projections[i]);
        if (distance < best_distance) {
            proj = projections[i];
            best_distance = distance;
        }
    }
    return proj;
}

static int get_turn_offset(direction_t dir)
{
    switch (dir) {
        case RIGHT:
            return 0;
        case UP:
            return 2;
        case LEFT:
            return 4;
        case DOWN:
            return 6;
        default:
            break;
    }
    return 0;
}


static local_direction_t get_sound_direction(vector2i_t listener_pos,
                                            vector2i_t sound_pos,
                                            direction_t dir)
{
    vector2i_t result = vector2i_sub(sound_pos, listener_pos);
    static const vector2i_t k_table[8] = {
        VEC2I(1, 0),
        VEC2I(1, -1),
        VEC2I(0, -1),
        VEC2I(-1, -1),
        VEC2I(-1, 0),
        VEC2I(-1, 1),
        VEC2I(0, 1),
        VEC2I(1, 1),
    };
    int dir_turn_offset = get_turn_offset(dir);
    int k = dir_turn_offset;

    for (int i = 0; i < 8; i++) {
        if (result.x == k_table[k].x && result.y == k_table[k].y)
            return i + 1;
        k += 1;
        if (k >= 8)
            k = 0;
    }
    return 0;
}

local_direction_t drone_get_sound_direction(const map_t *map,
                                            drone_t *d_from,
                                            drone_t *d_to)
{
    map_quarter_t d_quarter;
    vector2i_t projections[4];
    vector2i_t best_proj = {0};
    vector2i_t sound_pos = {0};

    if (d_from->pos.x == d_to->pos.x
        && d_from->pos.y == d_to->pos.y)
        return 0;
    d_quarter = drone_get_map_quarter(map, d_from);
    drone_get_sound_set_projections(map, projections,
        VEC2I((int)d_to->pos.x, (int)d_to->pos.y), d_quarter);
    best_proj = find_best_projection(
        VEC2I((int)d_from->pos.x, (int)d_from->pos.y), projections);
    sound_pos = drone_get_sound_entering_tile(d_from, best_proj);
    return get_sound_direction(best_proj, sound_pos, d_to->facing_direction);
}
