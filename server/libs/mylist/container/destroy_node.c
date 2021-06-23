/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** destroy_node
*/

#include <stdlib.h>
#include "mylist/container.h"

void destroy_node(node_t *node, node_dtor_t destructor)
{
    if (!node)
        return;
    if (node->data.ptr) {
        if (destructor) {
            destructor(node->data.ptr);
        } else {
            free(node->data.ptr);
        }
    }
    free(node);
}

void destroy_ptr_node(node_t *node, node_dtor_t destructor)
{
    if (!node)
        return;
    if (destructor && node->data.ptr)
        destructor(node->data.ptr);
    free(node);
}
