/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** tile
*/

#ifndef TILE_H_
#define TILE_H_

#include <mylist/ptr_list.h>

typedef struct tile_s
{
    ptr_list_t *players_on_tile;
    ptr_list_t *objects_on_tile;
    unsigned int pos_x;
    unsigned int pos_y;
} tile_t;

tile_t *create_tile(unsigned int pos_x, unsigned int pos_y);
void destroy_tile(tile_t *tile);

#endif /* !TILE_H_ */
