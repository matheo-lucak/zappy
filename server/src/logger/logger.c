/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** logger
*/

#include <stdarg.h>
#include <stdio.h>

#include "logger/logger.h"

void server_log(log_type_t type, ...)
{
    log_message_t m = logger_find_message_from_type(type);
    va_list ap;

    va_start(ap, type);
    printf("%s ", m.header);
    vprintf(m.message, ap);
    printf("\n");
    va_end(ap);
}