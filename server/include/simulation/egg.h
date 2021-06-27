/*
** EPITECH PROJECT, 2021
** server
** File description:
** egg
*/

#ifndef EGG_H_
#define EGG_H_

#define EGG_TIME_TO_HATCH 600

typedef struct egg_s
{
    int x;
    int y;
    int time_until_hatch;
} egg_t;

egg_t *egg_create(int x, int y);
void egg_destroy(egg_t *egg);

#endif /* !EGG_H_ */
