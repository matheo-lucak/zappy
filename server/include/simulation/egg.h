/*
** EPITECH PROJECT, 2021
** server
** File description:
** egg
*/

#ifndef EGG_H_
#define EGG_H_

#define EGG_TIME_TO_HATCH 600

#include "simulation/vector.h"

typedef struct egg_s
{
    vector2u_t pos;
    int time_until_hatch;
} egg_t;

egg_t *egg_create(vector2u_t pos);
void egg_destroy(egg_t *egg);

#endif /* !EGG_H_ */
