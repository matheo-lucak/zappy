/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_remove
*/

#include <string.h>
#include "mylist/generic_list.h"

int intern_generic_list_remove(list_t *this, const void *data, size_t size)
{
    if (!data || size == 0)
        return LIST_ERROR;
    list_foreach(node, this) {
        if (node->data.size != size)
            continue;
        if (memcmp(node->data.ptr, data, size) == 0) {
            list_pop(this, node->index);
            node_iter_end(&node);
            return LIST_SUCCESS;
        }
    }
    return LIST_ERROR;
}

int intern_generic_list_remove_cmp(list_t *this, const void *data,
                                size_t size, node_cmp_t comparator)
{
    if (!data || size == 0)
        return LIST_ERROR;
    list_foreach(node, this) {
        if (node->data.size != size)
            continue;
        if (comparator(node->data.ptr, data) == 0) {
            list_pop(this, node->index);
            node_iter_end(&node);
            return LIST_SUCCESS;
        }
    }
    return LIST_ERROR;
}