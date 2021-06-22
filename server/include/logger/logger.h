/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** logger
*/

#ifndef LOGGER_H_
#define LOGGER_H_

#include <stddef.h>

#define LOG_SERVER_RANGE_L        0
#define LOG_SERVER_RANGE_H        1023
#define LOG_NETWORK_RANGE_L       1024
#define LOG_NETWORK_RANGE_H       2047
#define LOG_SIMULATION_RANGE_L    2048
#define LOG_SIMULATION_RANGE_H    3071

#define LOG_SERVER_HEADER       "[SERVER]"
#define LOG_NETWORK_HEADER      "[NETWORK]"
#define LOG_SIMULATION_HEADER   "[SIMULATION]"
#define LOG_DEFAULT_HEADER      "[LOG]"

#define LOG_DEFAULT_MESSAGE     "Unkown message"

typedef enum
{
    LOG_SERVER_STARTED          = LOG_SERVER_RANGE_L,
    LOG_SERVER_STOPPED,
    LOG_SERVER_NEW_CLIENT,
    LOG_SERVER_CLIENT_LEFT,
    LOG_SERVER_CLIENT_TO_DRONE,
    LOG_SERVER_CLIENT_TO_SPECTATOR,
    LOG_SERVER_CLIENT_TO_ERROR,
    LOG_SERVER_INVALID_REQUEST,
    LOG_SERVER_INVALID_REQUEST_ARG,

    LOG_NETWORK_STARTED         = LOG_NETWORK_RANGE_L,
    LOG_NETWORK_STOPPED,
    LOG_NETWORK_LISTENING,

    LOG_SIMULATION_STARTED      = LOG_SIMULATION_RANGE_L,
    LOG_SIMULATION_STOPPED,
    LOG_SIMULATION_NEW_FORK
} log_type_t;

void server_log(log_type_t type, ...);

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
///
/// Internal Implementation
///
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

typedef struct log_info_s
{
    log_type_t  type;
    char *      message;
} log_info_t;

typedef struct log_message_s
{
    const char *  header;
    const char *  message;
} log_message_t;

extern const log_info_t log_info_map[];
extern const size_t log_info_map_size;

log_message_t logger_find_message_from_type(log_type_t type);

#endif /* !LOGGER_H_ */
