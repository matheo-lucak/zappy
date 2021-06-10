/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_rotate
*/

#include "mylist/generic_list.h"

void intern_generic_list_rotate_begin(list_t *this)
{
    container_rotate_begin((container_list_t *)&this->__c);
}

void intern_generic_list_rotate_end(list_t *this)
{
    container_rotate_end((container_list_t *)&this->__c);
}