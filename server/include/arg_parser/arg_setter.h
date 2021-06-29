/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** arg_setter
*/

#ifndef ZAPPY_ARG_SETTER_H_
#define ZAPPY_ARG_SETTER_H_

#include <stddef.h>

#include "arg_parser.h"

// Type of a classic arg_setter
// The arguments_t is the structure to fill
// If the option requires an argument, use optarg
// The '...' parameters are : int ac, char **av
typedef int (*arg_setter_t)(arguments_t *, ...);

typedef struct arg_setter_map
{
    int          option;
    arg_setter_t setter;
} arg_setter_map_t;

extern const arg_setter_map_t argument_setters[];

/**
* @brief Given a character matching an argument option,
*        it will return the matching arg_setter.
*
* @param option The character matching the argument option.
* @return arg_setter_t The matching arg_setter or NULL if none is matching.
*/
arg_setter_t arg_setter_get_from_option(int option);

//////////////////////
// Argument setters //
//////////////////////

/**
* @brief Sets the value of the port argument in arg
*        with the argument stored in 'optarg'.
*
* @param arg
* @param ... There's no variadic argument needed.
* @return int 0 on success, 1 on failure.
*/
int arg_setter_port(arguments_t *arg, ...);

/**
* @brief Sets the value of the width argument in arg
*        with the argument stored in 'optarg'.
*
* @param arg
* @param ... There's no variadic argument needed.
* @return int 0 on success, 1 on failure.
*/
int arg_setter_width(arguments_t *arg, ...);

/**
* @brief Sets the value of the height argument in arg
*        with the argument stored in 'optarg'.
*
* @param arg
* @param ... There's no variadic argument needed.
* @return int 0 on success, 1 on failure.
*/
int arg_setter_height(arguments_t *arg, ...);

/**
* @brief Sets the value of the name argument in arg.
*
* @param arg
* @param ... 'int ac, char **av' must follow.
* @return int 0 on success, 1 on failure.
*/
int arg_setter_name(arguments_t *arg, ...);

/**
* @brief Sets the value of the frequency argument in arg
*        with the argument stored in 'optarg'.
*
* @param arg
* @param ... There's no variadic argument needed.
* @return int 0 on success, 1 on failure.
*/
int arg_setter_frequency(arguments_t *arg, ...);

/**
* @brief Sets the value of the client_nb argument in arg
*        with the argument stored in 'optarg'.
*
* @param arg
* @param ... There's no variadic argument needed.
* @return int 0 on success, 1 on failure.
*/
int arg_setter_clients_nb(arguments_t *arg, ...);

#endif /* !ZAPPY_ARG_SETTER_H_ */
