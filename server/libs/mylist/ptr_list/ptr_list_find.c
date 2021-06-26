/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_find
*/

#include <string.h>
#include "mylist/ptr_list.h"

const node_t *intern_ptr_list_find(const ptr_list_t *this, const void *ptr)
{
    if (!ptr)
        return NULL;
    for (const node_t *node = list_begin(this); node; node = node->next) {
        if (node->data.ptr == ptr)
            return node;
    }
    return NULL;
}

const node_t *intern_ptr_list_find_cmp(const ptr_list_t *this,
                                        const void *ptr,
                                        node_cmp_t comparator)
{
    if (!ptr || !comparator)
        return NULL;
    for (const node_t *node = list_begin(this); node; node = node->next) {
        if (comparator(node->data.ptr, ptr) == 0)
            return node;
    }
    return NULL;
}