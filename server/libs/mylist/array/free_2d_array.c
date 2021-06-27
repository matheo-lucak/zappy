/*
** EPITECH PROJECT, 2021
** mylist
** File description:
** free_2d_array
*/

#include <stdlib.h>
#include "mylist/free_2d_array.h"

void free_2d_array(void *array)
{
    if (array) {
        for (size_t i = 0; ((void **)array)[i]; ++i)
            free(((void **)array)[i]);
        free(array);
    }
}