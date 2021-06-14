/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** map
*/

#include "logger/logger.h"

const log_info_t log_info_map[] =
{
    {
        .type = LOG_SERVER_STARTED,
        .message = "Started"
    },
    {
        .type = LOG_SERVER_STOPPED,
        .message = "Stopped"
    },
    {
        .type = LOG_SERVER_NEW_CLIENT,
        .message = "New client from: %s"
    },
    {
        .type = LOG_SERVER_CLIENT_LEFT,
        .message = "A client has left"
    },
        {
        .type = LOG_NETWORK_STARTED,
        .message = "Started"
    },
    {
        .type = LOG_NETWORK_STOPPED,
        .message = "Stopped"
    },
    {
        .type = LOG_NETWORK_LISTENING,
        .message = "Listening on port %d"
    },
    {
        .type = LOG_SIMULATION_STARTED,
        .message = "Started"
    },
        {
        .type = LOG_SIMULATION_STOPPED,
        .message = "Stopped"
    },
    {
        .type = LOG_SIMULATION_NEW_FORK,
        .message = "An egg has hatched at (%d, %d) facing %d"
    },
};

const size_t log_info_map_size = sizeof(log_info_map)/ sizeof(log_info_map[0]);
