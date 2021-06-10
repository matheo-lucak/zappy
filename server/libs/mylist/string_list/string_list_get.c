/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_get
*/

#include "mylist/string_list.h"

const node_t *intern_string_list_get(const string_list_t *this, long index)
{
    return container_get_node((container_list_t *)&this->__c, index);
}