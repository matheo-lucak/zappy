/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_infos
*/

#include "mylist/generic_list.h"

int intern_generic_list_empty(const list_t *this)
{
    return (list_len(this) == 0);
}

size_t intern_generic_list_length(const list_t *this)
{
    return this->__c.size;
}

const node_t *intern_generic_list_begin(const list_t *this)
{
    return this->__c.start;
}

const node_t *intern_generic_list_end(const list_t *this)
{
    return this->__c.end;
}

node_dtor_t intern_generic_list_get_dtor(const list_t *this)
{
    return this->__c.__dtor__;
}