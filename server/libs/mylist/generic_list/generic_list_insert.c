/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_insert
*/

#include "mylist/generic_list.h"

int intern_generic_list_push_front(list_t *this, const void *data, size_t size)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *element = create_node(data, size);

    return container_add_node_at_start(list, element);
}

int intern_generic_list_push_back(list_t *this, const void *data, size_t size)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *element = create_node(data, size);

    return container_add_node_at_end(list, element);
}

int intern_generic_list_insert(list_t *this, long index,
                                const void *data, size_t size)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *element = create_node(data, size);

    return container_add_node(list, element, index);
}