/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Request
*/

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#include "Request.hpp"

Request::Request(const char *format, ...) :
    is_valid(true)
{
    int needed = 0;
    char *buffer = NULL;

    va_list ap;
    va_list ap_copy;

    va_start(ap, format);
    va_copy(ap_copy, ap);
    if (!format) {
        is_valid = false;
        goto end;
    }
    needed = vsnprintf(NULL, 0, format, ap);
    if (needed < 0) {
        is_valid = false;
        goto end;
    }
    buffer = (char *)malloc(needed + 2);

    if (!buffer) {
        is_valid = false;
        goto end;
    }
    if (vsnprintf(buffer, needed + 1, format, ap_copy) < 0) {
        is_valid = false;
        goto end;
    }
    end:
    data = buffer;
    free(buffer);
    va_end(ap);
    va_end(ap_copy);
}