/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_reverse
*/

#include "mylist/string_list.h"

void intern_string_list_reverse(string_list_t *this)
{
    container_reverse((container_list_t *)&this->__c);
}