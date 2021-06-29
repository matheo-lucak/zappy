/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** arguments
*/

#ifndef ARGUMENTS_H_
#define ARGUMENTS_H_

#include <stddef.h>
#include <mylist/string_list.h>

typedef struct arguments
{
    unsigned short  port;
    unsigned int    width;
    unsigned int    height;
    size_t          clients_nb;
    size_t          freq;
    string_list_t   *team_names;
} arguments_t;

arguments_t *arguments_create(void);
void arguments_destroy(arguments_t *args);

/**
* @brief Returns default argument values.
*        port -> 0.
*        clients_nb -> 3.
*        width -> 10.
*        height -> 10.
*        freq -> 100.
*
* @return arguments_t The argument structure containing default values.
*/
void arguments_set_default_values(arguments_t *args);

#endif /* !ARGUMENTS_H_ */