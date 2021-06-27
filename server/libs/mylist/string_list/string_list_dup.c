/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_dup
*/

#include "mylist/string_list.h"

static int duplicate_nodes(container_list_t *dest, const container_list_t *src)
{
    node_t *dest_node = NULL;
    const node_t *src_node = src->start;

    for (; src_node; src_node = src_node->next) {
        dest_node = create_string_node(src_node->data.ptr);
        if (container_add_node_at_end(dest, dest_node) == LIST_ERROR)
            return LIST_ERROR;
    }
    return LIST_SUCCESS;
}

string_list_t *intern_string_list_duplicate(const string_list_t *this)
{
    string_list_t *dest = string_list_create();

    if (dest && !duplicate_nodes((container_list_t *)&dest->__c, &this->__c)) {
        string_list_destroy(dest);
    }
    return dest;
}