/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_dup
*/

#include "mylist/generic_list.h"

static int duplicate_nodes(container_list_t *dest, const container_list_t *src)
{
    node_t *dest_node = NULL;
    const node_t *src_node = src->start;

    for (; src_node; src_node = src_node->next) {
        dest_node = create_node(src_node->data.ptr, src_node->data.size);
        if (container_add_node_at_end(dest, dest_node) == LIST_ERROR)
            return LIST_ERROR;
    }
    return LIST_SUCCESS;
}

list_t *intern_generic_list_duplicate(const list_t *this)
{
    list_t *dest = generic_list_create(this->__c.__dtor__);

    if (dest && !duplicate_nodes((container_list_t *)&dest->__c, &this->__c)) {
        generic_list_destroy(dest);
    }
    return dest;
}