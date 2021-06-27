/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_infos
*/

#include "mylist/ptr_list.h"

int intern_ptr_list_empty(const ptr_list_t *this)
{
    return (list_len(this) == 0);
}

size_t intern_ptr_list_length(const ptr_list_t *this)
{
    return this->__c.size;
}

const node_t *intern_ptr_list_begin(const ptr_list_t *this)
{
    return this->__c.start;
}

const node_t *intern_ptr_list_end(const ptr_list_t *this)
{
    return this->__c.end;
}

node_dtor_t intern_ptr_list_get_dtor(const ptr_list_t *this)
{
    return this->__c.__dtor__;
}
