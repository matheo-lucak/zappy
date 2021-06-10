/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** string_list_contains
*/

#include "mylist/string_list.h"

int intern_string_list_contains(const string_list_t *this, const char *str)
{
    return (this->str_find(this, str) != NULL);
}