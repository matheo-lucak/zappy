/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_infos
*/

#include "mylist/string_list.h"

int intern_string_list_empty(const string_list_t *this)
{
    return (list_len(this) == 0);
}

size_t intern_string_list_length(const string_list_t *this)
{
    return this->__c.size;
}

const node_t *intern_string_list_begin(const string_list_t *this)
{
    return this->__c.start;
}

const node_t *intern_string_list_end(const string_list_t *this)
{
    return this->__c.end;
}

node_dtor_t intern_string_list_get_dtor(const string_list_t *this)
{
    return this->__c.__dtor__;
}