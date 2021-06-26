/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_clear
*/

#include "mylist/string_list.h"

void intern_string_list_clear(string_list_t *this)
{
    while (!list_empty(this))
        list_pop_back(this);
}