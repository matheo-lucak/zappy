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

// Type of a classic arg_setter
// The arguments_t is the structure to fill 
// If the option requires an argument, use optarg
// The '...' parameters are : int ac, char **av 
typedef int (*arg_setter_t)(arguments_t *, ...);

typedef struct arg_setter_map
{
    int             option;
    arg_setter_t    setter;
} arg_setter_map_t;

extern const arg_setter_map_t argument_setters[];

arg_setter_t arg_setter_get_from_option(int option);


/********** SETTERS **********/
int arg_setter_port(arguments_t *arg, ...);
int arg_setter_width(arguments_t *arg, ...);
int arg_setter_height(arguments_t *arg, ...);
int arg_setter_name(arguments_t *arg, ...);
int arg_setter_frequency(arguments_t *arg, ...);
int arg_setter_clients_nb(arguments_t *arg, ...);

#endif /* !ARG_SETTER_H_ */
