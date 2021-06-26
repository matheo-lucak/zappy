/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_remove
*/

#include <string.h>
#include "mylist/string_list.h"

int intern_string_list_remove(string_list_t *this, const char *s)
{
    if (!s)
        return LIST_ERROR;
    list_foreach(node, this) {
        if (strcmp(NODE_STR(node), s) == 0) {
            list_pop(this, node->index);
            node_iter_end(&node);
            return LIST_SUCCESS;
        }
    }
    return LIST_ERROR;
}

int intern_string_list_remove_cmp(string_list_t *this, const char *s,
                                node_cmp_t comparator)
{
    if (!s || !comparator)
        return LIST_ERROR;
    list_foreach(node, this) {
        if (comparator(NODE_STR(node), s) == 0) {
            list_pop(this, node->index);
            node_iter_end(&node);
            return LIST_SUCCESS;
        }
    }
    return LIST_ERROR;
}