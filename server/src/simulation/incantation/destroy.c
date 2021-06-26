/*
** EPITECH PROJECT, 2021
** server
** File description:
** destroy
*/

#include <stdlib.h>

#include "simulation/incantation.h"

void incantation_destroy(incantation_t *incantation)
{
    if (!incantation)
        return;
    free(incantation);
}
