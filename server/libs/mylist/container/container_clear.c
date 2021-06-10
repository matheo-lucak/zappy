/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** container_clear
*/

#include "mylist/container.h"

void container_clear(container_list_t *list)
{
    while (list->size > 0) {
        container_delete_first_node(list);
    }
}
