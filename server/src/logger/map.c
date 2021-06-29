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
        .type = LOG_SERVER_CLIENT_BLOCKED,
        .message = "A client is blocked"
    },
    {
        .type = LOG_SERVER_CLIENT_UNBLOCKED,
        .message = "A client is unblocked"
    },
    {
        .type = LOG_SERVER_CLIENT_TO_DRONE,
        .message = "A client became a drone"
    },
    {
        .type = LOG_SERVER_CLIENT_TO_SPECTATOR,
        .message = "A client became a spectator"
    },
    {
        .type = LOG_SERVER_CLIENT_TO_ERROR,
        .message = "A client can't change twice its type"
    },
    {
        .type = LOG_SERVER_INVALID_REQUEST,
        .message = "Invalid client request: \"%s\""
    },
    {
        .type = LOG_SERVER_INVALID_REQUEST_ARG,
        .message = "Invalid client request argument"
    },
    {
        .type = LOG_SERVER_INVALID_RESPONSE_FORMAT,
        .message = "Response format must not be NULL"
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
        .type = LOG_NETWORK_NEW_CLIENT,
        .message = "New client %d from: %s"
    },
    {
        .type = LOG_NETWORK_CLIENT_LEFT,
        .message = "Client %d has left"
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
        .type = LOG_SIMULATION_NEW_DRONE,
        .message = "A new drone spawned at (%d, %d) facing %d"
    },
    {
        .type = LOG_SIMULATION_NEW_EGG,
        .message = "A new egg spawned at (%d, %d)"
    },
    {
        .type = LOG_SIMULATION_EGG_HATCHED,
        .message = "An egg has hatched at (%d, %d)"
    },
    {
        .type = LOG_SIMULATION_DRONE_DIED,
        .message = "A drone ran out of food and died at (%d, %d)"
    },
};

const size_t log_info_map_size = sizeof(log_info_map) / sizeof(log_info_map[0]);
