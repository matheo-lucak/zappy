/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_merge
*/

#include "mylist/ptr_list.h"

void intern_ptr_list_merge(ptr_list_t *this, ptr_list_t *other)
{
    container_list_t *list1 = (container_list_t *)&this->__c;
    container_list_t *list2 = (other) ? (container_list_t *)&other->__c : NULL;

    if (!list2)
        return;
    container_merge(list1, list2);
}