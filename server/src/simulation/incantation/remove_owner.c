/*
** EPITECH PROJECT, 2021
** server
** File description:
** remove_owner
*/

#include "simulation/incantation.h"

void incantation_remove_owner(incantation_t *incantation)
{
    incantation->owner = NULL;
}
