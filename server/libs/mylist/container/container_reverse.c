/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** container_reverse
*/

#include "mylist/container.h"

static void swap_node_links(node_t *node)
{
    node_t *temp = node->previous;

    node->previous = node->next;
    node->next = temp;
}

void container_reverse(container_list_t *list)
{
    node_t *tail = list->end;

    for (node_t *node = tail; node; node = node->next)
        swap_node_links(node);
    list->end = list->start;
    list->start = tail;
}