/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** my_get_nbr
*/

#include "my.h"

static int get_sign(char **tmp)
{
    int sign_multiplier = 1;

    for (; **tmp && (**tmp == '-' || **tmp == '+'); *tmp += 1) {
        if (**tmp == '-')
            sign_multiplier *= -1;
    }
    return sign_multiplier;
}

int my_get_nbr(const char *str)
{
    char *tmp = (char *)str;
    int old_nb = 0;
    int nb = 0;
    int sign_multiplier = 1;

    if (!str)
        return 0;
    sign_multiplier = get_sign(&tmp);
    for (; *tmp; tmp += 1)  {
        if (!my_is_digit(*tmp))
            break;
        old_nb = nb;
        nb = nb * 10 + *tmp - '0';
        if (old_nb > nb)
            return 0;
    }
    return nb * sign_multiplier;
}
