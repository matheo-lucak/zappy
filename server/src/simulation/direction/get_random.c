/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace) [WSL: Ubuntu]
** File description:
** get_random
*/

#include <stdlib.h>
#include "simulation/direction.h"

direction_t direction_get_random()
{
    direction_t direction = rand() % 4;

    return direction;
}
