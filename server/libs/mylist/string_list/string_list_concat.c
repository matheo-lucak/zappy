/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_concat
*/

#include <string.h>
#include <stdlib.h>
#include "mylist/string_list.h"

static char *set_size_and_returns(char *str, size_t nmemb, size_t *length)
{
    if (length) {
        *length = nmemb;
    }
    return str;
}

static size_t get_str_size(const string_list_t *list, const char *sep)
{
    size_t size = 0;
    const size_t nb_str = list_len(list);
    int has_separator = (nb_str > 1 && sep != NULL && sep[0] != '\0');

    list_foreach(node, list) {
        size += node->data.size;
    }
    if (has_separator)
        size += (strlen(sep) * (nb_str - 1));
    return size;
}

char *string_list_concat(const string_list_t *list, const char *separator,
                        size_t *length)
{
    size_t size = (list) ? get_str_size(list, separator) : 0;
    char *str = (list) ? calloc(size + 1, sizeof(*str)) : NULL;

    if (!str)
        return set_size_and_returns(NULL, 0, length);
    list_foreach(node, list) {
        strcat(str, NODE_STR(node));
        if (node->next && separator && *separator)
            strcat(str, separator);
    }
    return set_size_and_returns(str, size, length);
}