/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** list_destroy
*/

#include <stdlib.h>
#include "mylist/string_list.h"

void string_list_destroy(string_list_t *list)
{
    if (list) {
        list_clear(list);
        free(list);
    }
}