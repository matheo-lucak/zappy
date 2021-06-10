/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_get
*/

#include "mylist/ptr_list.h"

const node_t *intern_ptr_list_get(const ptr_list_t *this, long index)
{
    return container_get_node((container_list_t *)&this->__c, index);
}