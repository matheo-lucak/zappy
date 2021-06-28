/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** get_tile_look_format
*/

#include <mylist.h>
#include <my.h>
#include "simulation/map.h"
#include "simulation/vector.h"

char *map_get_tile_look_format(const map_t *map, vector2u_t pos)
{
    char *buffer = NULL;
    tile_t *tile = map->tiles[pos.y][pos.x];
    resource_type_t resource;
    const resource_info_t *resource_info = NULL;

    if (!list_empty(tile->drones))
        buffer = my_str_cat(buffer, "player", true, false);
    for (size_t i = 1; i < list_len(tile->drones); i++)
        buffer = my_str_cat(buffer, " player", true, false);
    if (!list_empty(tile->drones) && !list_empty(tile->items))
        buffer = my_str_cat(buffer, " ", true, false);
    if (!list_empty(tile->items)) {
        list_foreach(node, tile->items) {
            resource = NODE_DATA(node, resource_type_t);
            resource_info = resource_get_info_from_type(resource);
            buffer = my_str_cat(buffer, resource_info->name, true, false);
            if (node->next)
                buffer = my_str_cat(buffer, " ", true, false);
        }
    }
    return buffer;
}
