/*
** EPITECH PROJECT, 2021
** server
** File description:
** clear_items
*/

#include <stdbool.h>
#include "simulation/tile.h"

void tile_clear_items(tile_t *tile)
{
    list_clear(tile->items);
}
