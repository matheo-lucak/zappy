/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_rotate
*/

#include "mylist/string_list.h"

void intern_string_list_rotate_begin(string_list_t *this)
{
    container_rotate_begin((container_list_t *)&this->__c);
}

void intern_string_list_rotate_end(string_list_t *this)
{
    container_rotate_end((container_list_t *)&this->__c);
}