/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_pop
*/

#include "mylist/ptr_list.h"

void intern_ptr_list_pop(ptr_list_t *this, long index)
{
    container_list_t *list = (container_list_t *)&this->__c;

    destroy_ptr_node(container_remove(list, index), list->__dtor__);
}

void intern_ptr_list_pop_front(ptr_list_t *this)
{
    container_list_t *list = (container_list_t *)&this->__c;

    destroy_ptr_node(container_remove_first_node(list), list->__dtor__);
}

void intern_ptr_list_pop_back(ptr_list_t *this)
{
    container_list_t *list = (container_list_t *)&this->__c;

    destroy_ptr_node(container_remove_last_node(list), list->__dtor__);
}