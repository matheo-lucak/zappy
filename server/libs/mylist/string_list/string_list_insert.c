/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_insert
*/

#include "mylist/string_list.h"

int intern_string_list_push_front(string_list_t *this, const char *str)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *element = (this) ? create_string_node(str) : NULL;

    return container_add_node_at_start(list, element);
}

int intern_string_list_push_back(string_list_t *this, const char *str)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *element = (this) ? create_string_node(str) : NULL;

    return container_add_node_at_end(list, element);
}

int intern_string_list_insert(string_list_t *this, long index, const char *str)
{
    container_list_t *list = (container_list_t *)&this->__c;
    node_t *element = (this) ? create_string_node(str) : NULL;

    return container_add_node(list, element, index);
}