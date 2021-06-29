/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** arg_parser
*/

#ifndef ARG_PARSER_H_
#define ARG_PARSER_H_

#include "arguments.h"

////////////////////////////////////////////////////////////////////////////////
/// \brief Parses ac and av from the main into arguments.\newline
///
/// The function uses getopt_long() to parse parameters.
///
/// The const extern variable used for getopt_long are:
///     - const struct option long_options[]
///     - const char *short_options
///
/// Those 2 tables help finding an option represented by a character.
///
/// To match each option to an action,
/// we use function pointers called arg_setter_t.
/// An extern matching table for arg_setters and options is named:
///     - const arg_setter_map_t argument_setters[]
///
/// The function exclusively handles non-positional arguments.
/// If positional arguments have to be parsed, consider the following code:
/// ```
///     static int parse_positional_args(int ac, char * const * av,
///                                             arguments_t * args)
///     {
///         int new_ac = ac - optind;
///         char * const * new_av = av + optind;
///
///         for (int i = 0; i < new_ac) {
///             printf("Positional argument: %s\n", new_av[i]);
///         }
///         return 0;
///     }
///```
///
////////////////////////////////////////////////////////////////////////////////
int parse_arguments(int ac, char * const * av, arguments_t * args);

#endif /* !ARG_PARSER_H_ */
