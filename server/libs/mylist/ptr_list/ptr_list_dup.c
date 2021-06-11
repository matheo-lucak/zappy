/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_dup
*/

#include "mylist/ptr_list.h"

static int duplicate_nodes(container_list_t *dest, const container_list_t *src)
{
    node_t *dest_node = NULL;
    const node_t *src_node = src->start;

    for (; src_node; src_node = src_node->next) {
        dest_node = create_ptr_node(src_node->data.ptr);
        if (container_add_node_at_end(dest, dest_node) == LIST_ERROR)
            return LIST_ERROR;
    }
    return LIST_SUCCESS;
}

ptr_list_t *intern_ptr_list_duplicate(const ptr_list_t *this)
{
    ptr_list_t *dest = ptr_list_create(this->__c.__dtor__);

    if (dest && !duplicate_nodes((container_list_t *)&dest->__c, &this->__c)) {
        ptr_list_destroy(dest);
    }
    return dest;
}