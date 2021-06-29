/*
** EPITECH PROJECT, 2021
** server [WSL: Ubuntu]
** File description:
** has_items
*/

#include "simulation/tile.h"

bool tile_has_items(tile_t *tile)
{
    return list_empty(tile->items);
}
