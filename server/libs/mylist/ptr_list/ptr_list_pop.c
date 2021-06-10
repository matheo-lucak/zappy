/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_pop
*/

#include "mylist/ptr_list.h"

void intern_ptr_list_pop(ptr_list_t *this, long index)
{
    container_delete_node((container_list_t *)&this->__c, index);
}

void intern_ptr_list_pop_front(ptr_list_t *this)
{
    container_delete_first_node((container_list_t *)&this->__c);
}

void intern_ptr_list_pop_back(ptr_list_t *this)
{
    container_delete_last_node((container_list_t *)&this->__c);
}