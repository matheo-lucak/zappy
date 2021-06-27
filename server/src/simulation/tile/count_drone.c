/*
** EPITECH PROJECT, 2021
** server
** File description:
** count_drone
*/

#include "simulation/tile.h"

size_t tile_count_drone(tile_t *tile)
{
    if (!tile)
        return 0;
    return list_len(tile->drones);
}
