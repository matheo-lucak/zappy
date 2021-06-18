/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_clear
*/

#include "mylist/generic_list.h"

void intern_generic_list_clear(list_t *this)
{
    while (!list_empty(this))
        list_pop_front(this);
}