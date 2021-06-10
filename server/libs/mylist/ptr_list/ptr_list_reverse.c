/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_reverse
*/

#include "mylist/ptr_list.h"

void intern_ptr_list_reverse(ptr_list_t *this)
{
    container_reverse((container_list_t *)&this->__c);
}