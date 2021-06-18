/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_pop
*/

#include <stdlib.h>
#include "mylist/ptr_list.h"

static void destroy_node(node_t *node, node_dtor_t destructor)
{
    if (!node)
        return;
    if (destructor && node->data.ptr)
        destructor(node->data.ptr);
    free(node);
}

void intern_ptr_list_pop(ptr_list_t *this, long index)
{
    container_list_t *list = (container_list_t *)&this->__c;

    destroy_node(container_remove(list, index), list->__dtor__);
}

void intern_ptr_list_pop_front(ptr_list_t *this)
{
    container_list_t *list = (container_list_t *)&this->__c;

    destroy_node(container_remove_first_node(list), list->__dtor__);
}

void intern_ptr_list_pop_back(ptr_list_t *this)
{
    container_list_t *list = (container_list_t *)&this->__c;

    destroy_node(container_remove_last_node(list), list->__dtor__);
}