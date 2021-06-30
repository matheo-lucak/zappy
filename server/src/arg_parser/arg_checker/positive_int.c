/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** arg_checker_positive_int
*/

#include <ctype.h>

int arg_checker_positive_int(char *arg)
{
    if (!arg)
        return -1;
    do {
        if (!isdigit(*arg))
            return 1;
        arg += 1;
    } while (*arg);
    return 0;
}
