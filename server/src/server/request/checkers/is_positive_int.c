/*
** EPITECH PROJECT, 2021
** server
** File description:
** is_positive_int
*/

#include <stdbool.h>
#include <ctype.h>

#include "simulation/resources.h"

bool request_arg_check_is_positive_int(char *arg)
{
    if (!arg)
        return false;
    do {
        if (!isdigit(*arg))
            return false;
        arg += 1;
    } while (*arg);
    return true;
}
