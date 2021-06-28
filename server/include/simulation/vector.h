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

#endif /* VECTOR_H_ */
