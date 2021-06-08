/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** arg_setter
*/

#ifndef ARG_SETTER_H_
#define ARG_SETTER_H_

#include <stddef.h>

#include "arg_parser.h"

typedef int (*arg_setter_t)(arguments_t *);

typedef struct arg_setter_map
{
    int             option;
    arg_setter_t    setter;
} arg_setter_map_t;

extern const arg_setter_map_t argument_setters[];
//= {
//    {.option = 0, .setter = NULL}
//};

arg_setter_t get_arg_setter_from_option(int option);

#endif /* !ARG_SETTER_H_ */
