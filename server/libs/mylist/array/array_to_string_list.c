/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** array_to_string_list
*/

#include "mylist/string_list.h"

string_list_t *array_to_string_list(const char *const *array)
{
    string_list_t *list = (array) ? string_list_create() : NULL;

    if (!list)
        return NULL;
    for (size_t i = 0; array[i]; ++i) {
        if (list->str_push_back(list, array[i]) == LIST_ERROR) {
            string_list_destroy(list);
            return NULL;
        }
    }
    return list;
}