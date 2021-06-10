/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_reverse
*/

#include "mylist/generic_list.h"

void intern_generic_list_reverse(list_t *this)
{
    container_reverse((container_list_t *)&this->__c);
}