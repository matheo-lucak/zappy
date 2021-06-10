/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** container_delete_node
*/

#include "mylist/container.h"

void container_delete_first_node(container_list_t *list)
{
    node_t *to_delete = container_remove_first_node(list);

    destroy_node(to_delete, list->__dtor__);
}

void container_delete_last_node(container_list_t *list)
{
    node_t *to_delete = container_remove_last_node(list);

    destroy_node(to_delete, list->__dtor__);
}

void container_delete_node(container_list_t *list, long index)
{
    node_t *to_delete = container_remove(list, index);

    destroy_node(to_delete, list->__dtor__);
}