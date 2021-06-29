/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** has_drones
*/

#include "simulation/tile.h"

bool tile_has_drones(tile_t *tile)
{
    return list_empty(tile->drones);
}
