/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_remove
*/

#include <string.h>
#include "mylist/ptr_list.h"

int intern_ptr_list_remove(ptr_list_t *this, const void *ptr)
{
    if (!ptr)
        return LIST_ERROR;
    list_foreach(node, this) {
        if (node->data.ptr == ptr) {
            list_pop(this, node->index);
            node_iter_end(&node);
            return LIST_SUCCESS;
        }
    }
    return LIST_ERROR;
}

int intern_ptr_list_remove_cmp(ptr_list_t *this, const void *ptr,
                            node_cmp_t comparator)
{
    if (!ptr || !comparator)
        return LIST_ERROR;
    list_foreach(node, this) {
        if (comparator(node->data.ptr, ptr) == 0) {
            list_pop(this, node->index);
            node_iter_end(&node);
            return LIST_SUCCESS;
        }
    }
    return LIST_ERROR;
}