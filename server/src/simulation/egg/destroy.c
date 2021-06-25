/*
** EPITECH PROJECT, 2021
** server
** File description:
** destroy
*/

#include <stdlib.h>

#include "simulation/egg.h"

void egg_destroy(egg_t *egg)
{
    if (!egg)
        return;
    free(egg);
}
