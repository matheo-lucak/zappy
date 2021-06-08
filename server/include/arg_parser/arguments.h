/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** arguments
*/

#ifndef ARGUMENTS_H_
#define ARGUMENTS_H_

#include <stddef.h>

typedef struct arguments
{
    unsigned short  port;
    unsigned int    width;
    unsigned int    height;
    size_t          clients_nb;
    size_t          freq;
} arguments_t;

#endif /* !ARGUMENTS_H_ */