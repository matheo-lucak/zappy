/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** arg_checker_positive_int
*/

#include <ctype.h>

int arg_checker_positive_int(char *arg)
{
    if (!arg)
        return -1;
    while (*arg) {
        if (!isdigit(*arg))
            return 1;
        arg++;
    }
    return 0;
}