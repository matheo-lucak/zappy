/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** get_from_option
*/

#include "arg_parser/arg_setter.h"

arg_setter_t arg_setter_get_from_option(int option)
{
    for (size_t i = 0; argument_setters[i].setter; i++) {
        if (argument_setters[i].option == option)
            return argument_setters[i].setter;
    }
    return NULL;
}
