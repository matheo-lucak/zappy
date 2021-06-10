/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_clear
*/

#include "mylist/ptr_list.h"

void intern_ptr_list_clear(ptr_list_t *this)
{
    container_clear((container_list_t *)&this->__c);
}