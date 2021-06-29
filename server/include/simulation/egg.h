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

/**
* @brief Creates a egg.
*
* @param pos The position of the new egg.
* @return response_t* A pointer to the newly allocated egg.
*/
egg_t *egg_create(vector2u_t pos);

/**
* @brief Releases memory previously allocated to a egg.
*
* @param egg The incantation to release memory from.
*/
void egg_destroy(egg_t *egg);

#endif /* !EGG_H_ */
