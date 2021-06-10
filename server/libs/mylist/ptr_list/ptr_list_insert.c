/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_insert
*/

#include "mylist/ptr_list.h"

int intern_ptr_list_push_front(ptr_list_t *this, void *ptr)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *element = create_ptr_node(ptr);

    return container_add_node_at_start(list, element);
}

int intern_ptr_list_push_back(ptr_list_t *this, void *ptr)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *element = create_ptr_node(ptr);

    return container_add_node_at_end(list, element);
}

int intern_ptr_list_insert(ptr_list_t *this, long index, void *ptr)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *element = create_ptr_node(ptr);

    return container_add_node(list, element, index);
}