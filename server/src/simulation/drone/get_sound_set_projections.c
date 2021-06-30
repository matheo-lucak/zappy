/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get_sound_set_projections
*/

#include "simulation/map.h"
#include "simulation/drone.h"

static void set_projection_top_left(const map_t *map, vector2i_t *proj,
                                    vector2i_t base)
{
    proj[0] = VEC2I(base.x, base.y);
    proj[1] = VEC2I(base.x - map->width, base.y);
    proj[2] = VEC2I(base.x, base.y - map->height);
    proj[3] = VEC2I(base.x - map->width, base.y - map->height);
}

static void set_projection_top_right(const map_t *map, vector2i_t *proj,
                                    vector2i_t base)
{
    proj[0] = VEC2I(base.x, base.y);
    proj[1] = VEC2I(base.x + map->width, base.y);
    proj[2] = VEC2I(base.x, base.y - map->height);
    proj[3] = VEC2I(base.x + map->width, base.y - map->height);
}

static void set_projection_bottom_left(const map_t *map, vector2i_t *proj,
                                        vector2i_t base)
{
    proj[0] = VEC2I(base.x, base.y);
    proj[1] = VEC2I(base.x - map->width, base.y);
    proj[2] = VEC2I(base.x, base.y + map->height);
    proj[3] = VEC2I(base.x - map->width, base.y + map->height);
}

static void set_projection_bottom_right(const map_t *map, vector2i_t *proj,
                                        vector2i_t base)
{
    proj[0] = VEC2I(base.x, base.y);
    proj[1] = VEC2I(base.x + map->width, base.y);
    proj[2] = VEC2I(base.x, base.y + map->height);
    proj[3] = VEC2I(base.x + map->width, base.y + map->height);
}

void drone_get_sound_set_projections(vector2i_t base, vector2i_t proj[4],
                                    const map_t *map, map_quarter_t quarter)
{
    switch (quarter) {
        case MAP_TOP_LEFT:
            set_projection_top_left(map, proj, base);
            break;
        case MAP_TOP_RIGHT:
            set_projection_top_right(map, proj, base);
            break;
        case MAP_BOTTOM_LEFT:
            set_projection_bottom_left(map, proj, base);
            break;
        case MAP_BOTTOM_RIGHT:
            set_projection_bottom_right(map, proj, base);
            break;
        default:
            break;
    }
}