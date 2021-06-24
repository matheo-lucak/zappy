/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** ptr_list_contains
*/

#include "mylist/ptr_list.h"

int intern_ptr_list_contains(const ptr_list_t *this, const void *ptr)
{
    return (this->ptr_find(this, ptr) != NULL);
}