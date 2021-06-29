/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** distance
*/

#include <math.h>

#include "simulation/vector.h"

double vector2i_distance(vector2i_t vec1, vector2i_t vec2)
{
    return sqrt(pow(vec2.x - vec1.x, 2) + pow(vec2.y - vec1.y, 2));
}

double vector2u_distance(vector2u_t vec1, vector2u_t vec2)
{
    return sqrt(pow(vec2.x - vec1.x, 2) + pow(vec2.y - vec1.y, 2));
}

double vector2f_distance(vector2f_t vec1, vector2f_t vec2)
{
    return sqrt(pow(vec2.x - vec1.x, 2) + pow(vec2.y - vec1.y, 2));
}
