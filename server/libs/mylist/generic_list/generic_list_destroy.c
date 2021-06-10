/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** list_destroy
*/

#include <stdlib.h>
#include "mylist/generic_list.h"

void generic_list_destroy(list_t *list)
{
    if (list) {
        list_clear(list);
        free(list);
    }
}