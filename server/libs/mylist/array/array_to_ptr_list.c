/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** array_to_ptr_list
*/

#include "mylist/ptr_list.h"

ptr_list_t *array_to_ptr_list(const void *array, node_dtor_t destructor)
{
    ptr_list_t *list = (array) ? ptr_list_create(destructor) : NULL;
    void *const *cast_array = array;

    if (!list)
        return NULL;
    for (size_t i = 0; cast_array[i]; ++i) {
        if (list->ptr_push_back(list, cast_array[i]) == LIST_ERROR) {
            ptr_list_destroy(list);
            return NULL;
        }
    }
    return list;
}