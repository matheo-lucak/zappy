/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** node_iterator
*/

#ifndef NODE_ITERATOR_H_
#define NODE_ITERATOR_H_

#include "node.h"

typedef struct node_iterator
{
    data_node_t data;
    size_t index;
    const node_t *previous;
    const node_t *next;
} node_iterator_t;

node_iterator_t *node_iter_start(const node_t *start, size_t index);

void node_iter_end(node_iterator_t **node);

void node_iter_next(node_iterator_t **node);

void node_iter_prev(node_iterator_t **node);

#endif /* !NODE_ITERATOR_H_ */
