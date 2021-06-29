/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** sub
*/

#include "simulation/vector.h"

vector2i_t vector2i_sub(vector2i_t vec1, vector2i_t vec2)
{
    return VEC2I(vec1.x - vec2.x, vec1.y - vec2.y);
}

vector2u_t vector2u_sub(vector2u_t vec1, vector2u_t vec2)
{
    return VEC2U(vec1.x - vec2.x, vec1.y - vec2.y);
}

vector2f_t vector2f_sub(vector2f_t vec1, vector2f_t vec2)
{
    return VEC2F(vec1.x - vec2.x, vec1.y - vec2.y);
}
