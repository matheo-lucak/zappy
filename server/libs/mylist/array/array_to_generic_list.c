/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** array_to_generic_list
*/

#include "mylist/generic_list.h"

list_t *array_to_generic_list(const void *array, size_t size, size_t nmemb,
                            node_dtor_t destructor)
{
    list_t *list = (array) ? generic_list_create(destructor) : NULL;

    if (!list)
        return NULL;
    for (size_t i = 0; i < nmemb; ++i) {
        if (list->push_back(list, (array + (size * i)), size) == LIST_ERROR) {
            generic_list_destroy(list);
            return NULL;
        }
    }
    return list;
}