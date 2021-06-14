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
        .type = LOG_SERVER_LISTENING,
        .message = "Listening on port %d"
    },
    {
        .type = LOG_SERVER_NEW_CLIENT,
        .message = "New client from: %s"
    },
    {
        .type = LOG_SERVER_CLIENT_LEFT,
        .message = "A client has left"
    },
};

const size_t log_info_map_size = sizeof(log_info_map)/ sizeof(log_info_map[0]);
