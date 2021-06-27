/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_get
*/

#include "mylist/generic_list.h"

const node_t *intern_generic_list_get(const list_t *this, long index)
{
    return container_get_node(&this->__c, index);
}