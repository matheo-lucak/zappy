/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_to_array
*/

#include <string.h>
#include <stdlib.h>
#include "mylist/ptr_list.h"

void *ptr_list_to_array(const ptr_list_t *list, size_t *length)
{
    size_t nmemb = (list) ? list_len(list) : 0;
    void **array = (list) ? calloc(nmemb + 1, sizeof(*array)) : NULL;
    size_t start = 0;

    if (array) {
        list_foreach(node, list) {
            array[start++] = node->data.ptr;
        }
    } else {
        nmemb = 0;
    }
    if (length)
        *length = nmemb;
    return array;
}