/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** container_reverse
*/

#include "mylist/container.h"

static void swap_node_data(data_node_t *first, data_node_t *second)
{
    data_node_t copy = *first;

    *first = *second;
    *second = copy;
}

void container_reverse(container_list_t *list)
{
    size_t index_forward = 0;
    size_t index_backward = 0;
    node_t *node_forward = NULL;
    node_t *node_backward = NULL;

    if (list->size <= 1)
        return;
    index_backward = list->size - 1;
    node_forward = list->start;
    node_backward = list->end;
    for (; index_forward < index_backward; ++index_forward, --index_backward) {
        swap_node_data(&node_forward->data, &node_backward->data);
        node_forward = node_forward->next;
        node_backward = node_backward->previous;
    }
}