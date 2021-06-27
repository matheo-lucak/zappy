/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** my_str_cat
*/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"

static void free_concatenated(char *first, char *second,
                            bool free_first, bool free_second)
{
    if (free_first)
        free(first);
    if (free_second)
        free(second);
}

static char *handle_null(char *first, char *second,
                        bool free_first, bool free_second)
{
    char *result = NULL;

    if (!first) {
        result = second ? strdup(second) : NULL;
        if (free_second)
            free(second);
        return result;
    }
    result = strdup(first);
    if (free_first)
        free(first);
    return result;
}

char *my_str_cat(char *first, char *second, bool free_first, bool free_second)
{
    char *result = NULL;
    ssize_t len_first = my_str_len(first);
    ssize_t len_second = my_str_len(second);
    size_t size = len_first + len_second;

    if (!first || !second)
        return handle_null(first, second, free_first, free_second);
    result = calloc(1, sizeof(char) * (size + 1));
    if (!result) {
        free_concatenated(first, second, free_first, free_second);
        return NULL;
    }
    strcpy(result, first);
    strcpy(result + len_first, second);
    result[size] = '\0';
    free_concatenated(first, second, free_first, free_second);
    return result;
}
