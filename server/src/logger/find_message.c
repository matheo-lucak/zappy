/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** find_info
*/

#include "logger/logger.h"

static char *logger_find_header(log_type_t type)
{
    if (LOG_SERVER_RANGE_L <= type && LOG_SERVER_RANGE_H >= type)
        return LOG_SERVER_HEADER;
    if (LOG_NETWORK_RANGE_L <= type && LOG_NETWORK_RANGE_H >= type)
        return LOG_NETWORK_HEADER;
    if (LOG_SIMULATION_RANGE_L <= type && LOG_SIMULATION_RANGE_H >= type)
        return LOG_SIMULATION_HEADER;
    return LOG_DEFAULT_HEADER;
}

static char *logger_find_message(log_type_t type)
{
    for (size_t i = 0; i < log_info_map_size; i++) {
        if (log_info_map[i].type == type)
            return log_info_map[i].message;
    }
    return LOG_DEFAULT_MESSAGE;
}

log_message_t logger_find_message_from_type(log_type_t type)
{
    log_message_t m = {0};

    m.header = logger_find_header(type);
    m.message = logger_find_message(type);
    return m;
}