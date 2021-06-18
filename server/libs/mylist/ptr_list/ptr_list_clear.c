/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_clear
*/

#include "mylist/ptr_list.h"

void intern_ptr_list_clear(ptr_list_t *this)
{
    while (!list_empty(this))
        list_pop_front(this);
}