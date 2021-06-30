/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** logger
*/

#ifndef ZAPPY_LOGGER_H_
#define ZAPPY_LOGGER_H_

#include <stddef.h>

#define LOG_SERVER_RANGE_L     0
#define LOG_SERVER_RANGE_H     1023
#define LOG_NETWORK_RANGE_L    1024
#define LOG_NETWORK_RANGE_H    2047
#define LOG_SIMULATION_RANGE_L 2048
#define LOG_SIMULATION_RANGE_H 3071

#define LOG_SERVER_HEADER      "[SERVER]"
#define LOG_NETWORK_HEADER     "[NETWORK]"
#define LOG_SIMULATION_HEADER  "[SIMULATION]"
#define LOG_DEFAULT_HEADER     "[LOG]"

#define LOG_DEFAULT_MESSAGE    "Unkown message"

typedef enum
{
    LOG_SERVER_STARTED          = LOG_SERVER_RANGE_L,
    LOG_SERVER_STOPPED,
    LOG_SERVER_CLIENT_BLOCKED,
    LOG_SERVER_CLIENT_UNBLOCKED,
    LOG_SERVER_CLIENT_TO_DRONE,
    LOG_SERVER_CLIENT_TO_SPECTATOR,
    LOG_SERVER_CLIENT_TO_ERROR,
    LOG_SERVER_ACCEPTED_VALID_REQUEST,
    LOG_SERVER_IGNORED_VALID_REQUEST,
    LOG_SERVER_INVALID_REQUEST,
    LOG_SERVER_INVALID_REQUEST_ARG,
    LOG_SERVER_INVALID_RESPONSE_FORMAT,

    LOG_NETWORK_STARTED         = LOG_NETWORK_RANGE_L,
    LOG_NETWORK_STOPPED,
    LOG_NETWORK_LISTENING,
    LOG_NETWORK_NEW_CLIENT,
    LOG_NETWORK_CLIENT_LEFT,

    LOG_SIMULATION_STARTED      = LOG_SIMULATION_RANGE_L,
    LOG_SIMULATION_STOPPED,
    LOG_SIMULATION_NEW_DRONE,
    LOG_SIMULATION_NEW_EGG,
    LOG_SIMULATION_EGG_HATCHED,
    LOG_SIMULATION_DRONE_DIED,
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

/**
* @brief Gets the log message matching the log_type given.
*
* @param type The log type.
* @return log_message_t The log message matching the given type.
*                       If not found, fills it with default values.
*/
log_message_t logger_find_message_from_type(log_type_t type);

#endif /* !ZAPPY_LOGGER_H_ */
