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
    node_t *node_forward = list->start;
    node_t *node_backward = list->end;
    size_t index_forward = 0;
    size_t index_backward = list->size - 1;

    if (list->size <= 1)
        return;
    while (index_forward < index_backward) {
        swap_node_data(&node_forward->data, &node_backward->data);
        node_forward = node_forward->next;
        node_backward = node_backward->previous;
        ++index_forward;
        --index_backward;
    }
}