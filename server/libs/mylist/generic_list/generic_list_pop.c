/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_pop
*/

#include "mylist/generic_list.h"

void intern_generic_list_pop(list_t *this, long index)
{
    container_delete_node((container_list_t *)&this->__c, index);
}

void intern_generic_list_pop_front(list_t *this)
{
    container_delete_first_node((container_list_t *)&this->__c);
}

void intern_generic_list_pop_back(list_t *this)
{
    container_delete_last_node((container_list_t *)&this->__c);
}