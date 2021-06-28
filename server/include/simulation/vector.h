/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** vector
*/

#ifndef VECTOR_H_
#define VECTOR_H_

typedef struct
{
    int x;
    int y;
} vector2i_t;

typedef struct
{
    unsigned int x;
    unsigned int y;
} vector2u_t;

typedef struct
{
    float x;
    float y;
} vector2f_t;

#define VEC2I(x_, y_) (vector2i_t){.x = x_, .y = y_}
#define VEC2U(x_, y_) (vector2u_t){.x = x_, .y = y_}
#define VEC2F(x_, y_) (vector2f_t){.x = x_, .y = y_}

vector2i_t vector2i_add(vector2i_t vec1, vector2i_t vec2);
vector2u_t vector2u_add(vector2u_t vec1, vector2u_t vec2);
vector2f_t vector2f_add(vector2f_t vec1, vector2f_t vec2);

vector2i_t vector2i_sub(vector2i_t vec1, vector2i_t vec2);
vector2u_t vector2u_sub(vector2u_t vec1, vector2u_t vec2);
vector2f_t vector2f_sub(vector2f_t vec1, vector2f_t vec2);

double vector2i_distance(vector2i_t vec1, vector2i_t vec2);
double vector2u_distance(vector2u_t vec1, vector2u_t vec2);
double vector2f_distance(vector2f_t vec1, vector2f_t vec2);

#endif /* VECTOR_H_ */
