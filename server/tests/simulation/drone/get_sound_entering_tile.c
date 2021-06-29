/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** get_sound_entering_tile
*/

#include <criterion/criterion.h>
#include "simulation/drone.h"

Test(drone_get_sound_entering_tile, simple_subject_example)
{
    drone_t *d1 = drone_create(VEC2U(2, 9), true);
    vector2i_t d2_proj_position = VEC2I(5, 13);
    vector2i_t tile_pos = VEC2I(0, 0);

    tile_pos = drone_get_sound_entering_tile(d1, d2_proj_position);
    cr_expect(tile_pos.x == 4);
    cr_expect(tile_pos.y == 12);
    drone_destroy(d1);
}

Test(drone_get_sound_entering_tile, simple_straight_line)
{
    drone_t *d1 = drone_create(VEC2U(2, 9), true);
    vector2i_t d2_proj_position = VEC2I(-1, 9);
    vector2i_t tile_pos = VEC2I(0, 0);

    tile_pos = drone_get_sound_entering_tile(d1, d2_proj_position);
    cr_expect(tile_pos.x == 0);
    cr_expect(tile_pos.y == 9);
    drone_destroy(d1);
}

Test(drone_get_sound_entering_tile, hard_same_position)
{
    drone_t *d1 = drone_create(VEC2U(0, 0), true);
    vector2i_t d2_proj_position = VEC2I(0, 0);
    vector2i_t tile_pos = VEC2I(0, 0);

    tile_pos = drone_get_sound_entering_tile(d1, d2_proj_position);
    cr_expect(tile_pos.x == 0);
    cr_expect(tile_pos.y == 0);
    drone_destroy(d1);
}

Test(drone_get_sound_entering_tile, hard_faraway_position)
{
    drone_t *d1 = drone_create(VEC2U(2, 2), true);
    vector2i_t d2_proj_position = VEC2I(10, -13);
    vector2i_t tile_pos = VEC2I(0, 0);

    tile_pos = drone_get_sound_entering_tile(d1, d2_proj_position);
    cr_expect(tile_pos.x == 9);
    cr_expect(tile_pos.y == -12);
    drone_destroy(d1);
}
