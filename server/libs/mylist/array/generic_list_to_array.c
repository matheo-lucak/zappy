/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_to_array
*/

#include <string.h>
#include <stdlib.h>
#include "mylist/generic_list.h"

static size_t get_allocation_size(const list_t *list)
{
    size_t size = 0;

    if (list) {
        list_foreach(node, list) {
            size += node->data.size;
        }
    }
    return size;
}

void *generic_list_to_array(const list_t *list, size_t *length)
{
    const size_t alloc_size = get_allocation_size(list);
    void *array = (alloc_size > 0) ? malloc(alloc_size) : NULL;
    size_t start = 0;
    size_t array_size = 0;

    if (array) {
        list_foreach(node, list) {
            memcpy(array + start, node->data.ptr, node->data.size);
            start += node->data.size;
            ++array_size;
        }
    }
    if (length)
        *length = array_size;
    return array;
}