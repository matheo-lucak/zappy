/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** container_rotate
*/

#include "mylist/container.h"

void container_rotate_begin(container_list_t *list)
{
    if (list->size <= 1)
        return;
    container_add_node_at_end(list, container_remove_first_node(list));
}

void container_rotate_end(container_list_t *list)
{
    if (list->size <= 1)
        return;
    container_add_node_at_start(list, container_remove_last_node(list));
}