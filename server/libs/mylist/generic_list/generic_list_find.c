/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_find
*/

#include <string.h>
#include "mylist/generic_list.h"

const node_t *intern_generic_list_find(const list_t *this,
                                    const void *data, size_t size)
{
    if (!data || size == 0)
        return NULL;
    for (const node_t *node = list_begin(this); node; node = node->next) {
        if (node->data.size != size)
            continue;
        if (memcmp(node->data.ptr, data, size) == 0)
            return node;
    }
    return NULL;
}

const node_t *intern_generic_list_find_cmp(const list_t *this,
                                        const void *data,
                                        size_t size,
                                        node_cmp_t comparator)
{
    if (!data || !comparator)
        return NULL;
    for (const node_t *node = list_begin(this); node; node = node->next) {
        if (node->data.size != size)
            continue;
        if (comparator(node->data.ptr, data) == 0)
            return node;
    }
    return NULL;
}