/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_to_array
*/

#include <string.h>
#include <stdlib.h>
#include "mylist/string_list.h"

static char **set_size_and_returns(char **array, size_t nmemb, size_t *length)
{
    if (length) {
        *length = nmemb;
    }
    return array;
}

char **string_list_to_array(const string_list_t *list, size_t *length)
{
    size_t nmemb = (list) ? list_len(list) : 0;
    char **array = (list) ? calloc(nmemb + 1, sizeof(*array)) : NULL;
    size_t start = 0;

    if (!array)
        return set_size_and_returns(NULL, 0, length);
    list_foreach(node, list) {
        array[start] = strdup(NODE_STR(node));
        if (!(array[start])) {
            free_2d_array(array);
            node_iter_end(&node);
            return set_size_and_returns(NULL, 0, length);
        }
        ++start;
    }
    return set_size_and_returns(array, nmemb, length);
}