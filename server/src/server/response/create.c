/*
** EPITECH PROJECT, 2021
** server
** File description:
** create
*/

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#include "logger/logger.h"

#include "server/response/response.h"

static int response_create_data_error(va_list ap, va_list ap_copy)
{
    va_end(ap);
    va_end(ap_copy);
    return -1;
}

static int response_create_data(response_t * res, const char *format,
                                                        va_list ap)
{
    int needed = 0;
    va_list ap_copy;

    va_copy(ap_copy, ap);
    needed = vsnprintf(NULL, 0, format, ap);
    if (needed < 0)
        return response_create_data_error(ap, ap_copy);
    res->data = malloc(needed + 1);
    if (!res->data)
        return response_create_data_error(ap, ap_copy);
    if (vsnprintf(res->data, needed + 1, format, ap_copy) < 0)
        return response_create_data_error(ap, ap_copy);
    return 0;
}

response_t *response_create(const char *format, ...)
{
    response_t *res = NULL;
    va_list ap;

    va_start(ap, format);
    if (!format) {
        server_log(LOG_SERVER_INVALID_RESPONSE_FORMAT);
        return NULL;
    }
    res = calloc(1, sizeof(response_t));
    if (!res)
        return NULL;
    res->data = NULL;
    if (response_create_data(res, format, ap) != 0) {
        response_destroy(res);
        return NULL;
    }
    return res;
}
