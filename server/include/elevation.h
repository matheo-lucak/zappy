/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** elevation
*/

#ifndef ELEVATION_H_
#define ELEVATION_H_

#include <stddef.h>

#include "resource.h"

typedef struct elevation_requirement_s
{
    size_t player_nb;
    size_t requirements[RESOURCE_NB];
} elevation_requirement_t;

#define ELEVATION_MAX_LVL   8

#endif /* !ELEVATION_H_ */