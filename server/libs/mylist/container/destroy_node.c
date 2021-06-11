/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** destroy_node
*/

#include <stdlib.h>
#include <string.h>
#include "mylist/container.h"

void destroy_node(node_t *node, node_dtor_t destructor)
{
    if (!node)
        return;
    if (destructor && node->data.ptr) {
        destructor(node->data.ptr);
    } else if (!(node->data.hold_ptr)) {
        free(node->data.ptr);
    }
    memset(node, 0, sizeof(*node));
    free(node);
}