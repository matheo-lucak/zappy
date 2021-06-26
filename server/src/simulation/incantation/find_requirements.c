/*
** EPITECH PROJECT, 2021
** server
** File description:
** find_requirements
*/

#include "simulation/incantation.h"

const elevation_requirement_t *incantation_find_requirements(size_t drone_lvl)
{
    for (size_t i = 0; i < elevation_requirements_size; i++) {
        if (elevation_requirements[i].drone_lvl == drone_lvl)
            return &elevation_requirements[i];
    }
    return NULL;
}