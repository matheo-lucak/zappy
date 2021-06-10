/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_emplace
*/

#include <limits.h>
#include "mylist/string_list.h"

char *intern_string_list_emplace(string_list_t *this, long idx, size_t size)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *element =  create_empty_node(size + (size < ULONG_MAX));

    container_add_node(list, element, idx);
    return NODE_STR(element);
}

char *intern_string_list_emplace_front(string_list_t *this, size_t size)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *element =  create_empty_node(size + (size < ULONG_MAX));

    container_add_node_at_start(list, element);
    return NODE_STR(element);
}

char *intern_string_list_emplace_back(string_list_t *this, size_t size)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *element =  create_empty_node(size + (size < ULONG_MAX));

    container_add_node_at_end(list, element);
    return NODE_STR(element);
}