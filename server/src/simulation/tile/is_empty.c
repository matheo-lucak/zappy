/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** is_empty
*/

#include "simulation/tile.h"

bool tile_is_empty(tile_t *tile)
{
    return list_empty(tile->drones) && list_empty(tile->items);
}
