/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_emplace
*/

#include "mylist/generic_list.h"

void *intern_generic_list_emplace_front(list_t *this, size_t size)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *element = create_empty_node(size);

    if (container_add_node_at_start(list, element) == LIST_ERROR)
        return NULL;
    return element->data.ptr;
}

void *intern_generic_list_emplace_back(list_t *this, size_t size)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *element = create_empty_node(size);

    if (container_add_node_at_end(list, element) == LIST_ERROR)
        return NULL;
    return element->data.ptr;
}

void *intern_generic_list_emplace(list_t *this, long index, size_t size)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *element = create_empty_node(size);

    if (container_add_node(list, element, index) == LIST_ERROR)
        return NULL;
    return element->data.ptr;
}