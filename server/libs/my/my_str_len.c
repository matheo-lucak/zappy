/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** my_str_len
*/

#include <unistd.h>

ssize_t my_str_len(const char *str)
{
    ssize_t i = -1;

    if (str)
        for (; str[++i];);
    return i;
}
