/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_merge
*/

#include "mylist/generic_list.h"

void intern_generic_list_merge(list_t *this, list_t *other)
{
    container_list_t *list1 = (container_list_t *)&this->__c;
    container_list_t *list2 = (other) ? (container_list_t *)&other->__c : NULL;

    if (!list2)
        return;
    container_merge(list1, list2);
}