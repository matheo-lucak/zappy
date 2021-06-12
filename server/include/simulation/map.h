/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include "simulation/tile.h"

typedef struct map_s
{
    unsigned int width;
    unsigned int height;
    tile_t ***tiles;
} map_t;

map_t *create_map(unsigned int width, unsigned int height);
void destroy_map(map_t *map);

#endif /* !MAP_H_ */
