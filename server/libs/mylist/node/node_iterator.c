/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** node_iterator
*/

#include <stdlib.h>
#include "mylist/node_iterator.h"

node_iterator_t *node_iter_start(const node_t *start, size_t index)
{
    node_iterator_t *iter = (start) ? malloc(sizeof(*iter)) : NULL;

    if (iter) {
        iter->data = start->data;
        iter->index = index;
        iter->next = start->next;
        iter->previous = start->previous;
    }
    return iter;
}

void node_iter_end(node_iterator_t **node)
{
    if (node) {
        free(*node);
        *node = NULL;
    }
}

void node_iter_next(node_iterator_t **node)
{
    if (!node || !(*node))
        return;
    if ((*node)->next) {
        (*node)->data = (*node)->next->data;
        (*node)->index += 1;
        (*node)->previous = (*node)->next->previous;
        (*node)->next = (*node)->next->next;
    } else {
        node_iter_end(node);
    }
}

void node_iter_prev(node_iterator_t **node)
{
    if (!node || !(*node))
        return;
    if ((*node)->previous) {
        (*node)->data = (*node)->previous->data;
        (*node)->index -= 1;
        (*node)->next = (*node)->previous->next;
        (*node)->previous = (*node)->previous->previous;
    } else {
        node_iter_end(node);
    }
}
