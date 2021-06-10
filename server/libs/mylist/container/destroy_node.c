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
    void *data = NULL;

    if (!node)
        return;
    if (node->data.hold_ptr) {
        data = *((void **)(node->data.ptr));
        if (destructor && data)
            destructor(data);
        free(node->data.ptr);
    } else {
        data = node->data.ptr;
        if (destructor && data)
            destructor(data);
        else
            free(data);
    }
    memset(node, 0, sizeof(*node));
    free(node);
}