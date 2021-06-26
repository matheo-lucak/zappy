/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_find
*/

#include <string.h>
#include "mylist/string_list.h"

const node_t *intern_string_list_find(const string_list_t *this, const char *s)
{
    if (!s)
        return NULL;
    for (const node_t *node = list_begin(this); node; node = node->next) {
        if (strcmp(NODE_STR(node), s) == 0)
            return node;
    }
    return NULL;
}

const node_t *intern_string_list_find_cmp(const string_list_t *this,
                                        const char *s,
                                        node_cmp_t comparator)
{
    if (!s || !comparator)
        return NULL;
    for (const node_t *node = list_begin(this); node; node = node->next) {
        if (comparator(NODE_STR(node), s) == 0)
            return node;
    }
    return NULL;
}