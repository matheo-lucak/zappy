/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_pop
*/

#include <stdlib.h>
#include "mylist/string_list.h"

void intern_string_list_pop(string_list_t *this, long index)
{
    container_delete_node((container_list_t *)&this->__c, index);
}

void intern_string_list_pop_front(string_list_t *this)
{
    container_delete_first_node((container_list_t *)&this->__c);
}

void intern_string_list_pop_back(string_list_t *this)
{
    container_delete_last_node((container_list_t *)&this->__c);
}