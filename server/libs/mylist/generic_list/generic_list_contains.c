/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** generic_list_contains
*/

#include "mylist/generic_list.h"

int intern_generic_list_contains(const list_t *this,
                                const void *data, size_t size)
{
    return (this->find(this, data, size) != NULL);
}
