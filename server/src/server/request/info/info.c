/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** info
*/

#include "server/request/info.h"

const request_info_t default_request_info =
{
    .name = "Default request",
    .type = RQ_DEFAULT,
    .handler = &request_handler_default,
    .time_limit = 0,
    .requirements = (request_requirements_t [])
    {
        {
            .client_type    = CLIENT_UNKNOWN,
            .arg_number     = 0,
            .arg_checkers   = (request_arg_checker_t []) {NULL}
        }
    }
};

const request_info_t request_info_map[] =
{
    {
        .name = "Forward",
        .type = RQ_CMD_FORWARD,
        .handler = &request_handler_cmd_forward,
        .time_limit = 7,
        .requirements = (request_requirements_t [])
        {
            {
                .client_type    = CLIENT_DRONE,
                .arg_number     = 0,
                .arg_checkers   = (request_arg_checker_t []) {NULL}
            }
        }
    },
    {
        .name = "Right",
        .type = RQ_CMD_RIGHT,
        .handler = &request_handler_cmd_right,
        .time_limit = 7,
        .requirements = (request_requirements_t [])
        {
            {
                .client_type    = CLIENT_DRONE,
                .arg_number     = 0,
                .arg_checkers   = (request_arg_checker_t []) {NULL}
            }
        }
    },
    {
        .name = "Left",
        .type = RQ_CMD_LEFT,
        .handler = &request_handler_cmd_left,
        .time_limit = 7,
        .requirements = (request_requirements_t [])
        {
            {
                .client_type    = CLIENT_DRONE,
                .arg_number     = 0,
                .arg_checkers   = (request_arg_checker_t []) {NULL}
            }
        }
    },
    {
        .name = "Look",
        .type = RQ_CMD_LOOK,
        .handler = &request_handler_cmd_look,
        .time_limit = 7,
        .requirements = (request_requirements_t [])
        {
            {
                .client_type    = CLIENT_DRONE,
                .arg_number     = 0,
                .arg_checkers   = (request_arg_checker_t []) {NULL}

            }
        }
    },
    {
        .name = "Inventory",
        .type = RQ_CMD_INVENTORY,
        .handler = &request_handler_cmd_inventory,
        .time_limit = 1,
        .requirements = (request_requirements_t [])
        {
            {
                .client_type    = CLIENT_DRONE,
                .arg_number     = 0,
                .arg_checkers   = (request_arg_checker_t []) {NULL}

            }
        }
    },
    {
        .name = "Broadcast",
        .type = RQ_CMD_BROADCAST,
        .handler = &request_handler_cmd_broadcast,
        .time_limit = 7,
        .requirements = (request_requirements_t [])
        {
            {
                .client_type    = CLIENT_DRONE,
                .arg_number     = RQ_REQUIRE_NO_ARG,
                .arg_checkers   = (request_arg_checker_t []) {NULL}
            }
        }
    },
    {
        .name = "Connect_nbr",
        .type = RQ_CMD_CONNECT_NBR,
        .handler = &request_handler_cmd_connect_nbr,
        .time_limit = 0,
        .requirements = (request_requirements_t [])
        {
            {
                .client_type    = CLIENT_DRONE,
                .arg_number     = 0,
                .arg_checkers   = (request_arg_checker_t []) {NULL}

            }
        }
    },
    {
        .name = "Fork",
        .type = RQ_CMD_FORK,
        .handler = &request_handler_cmd_fork,
        .time_limit = 42,
        .requirements = (request_requirements_t [])
        {
            {
                .client_type    = CLIENT_DRONE,
                .arg_number     = 0,
                .arg_checkers   = (request_arg_checker_t []) {NULL}

            }
        }
    },
    {
        .name = "Eject",
        .type = RQ_CMD_EJECT,
        .handler = &request_handler_cmd_eject,
        .time_limit = 7,
        .requirements = (request_requirements_t [])
        {
            {
                .client_type    = CLIENT_DRONE,
                .arg_number     = 0,
                .arg_checkers   = (request_arg_checker_t []) {NULL}

            }
        }
    },
    {
        .name = "Take",
        .type = RQ_CMD_TAKE_OBJECT,
        .handler = &request_handler_cmd_take,
        .time_limit = 7,
        .requirements = (request_requirements_t [])
        {
            {
                .client_type    = CLIENT_DRONE,
                .arg_number     = 1,
                .arg_checkers   = (request_arg_checker_t [])
                    {&request_arg_check_is_resource}
            }
        }
    },
    {
        .name = "Set",
        .type = RQ_CMD_SET_OBJECT,
        .handler = &request_handler_cmd_set,
        .time_limit = 7,
        .requirements = (request_requirements_t [])
        {
            {
                .client_type    = CLIENT_DRONE,
                .arg_number     = 1,
                .arg_checkers   = (request_arg_checker_t [])
                    {&request_arg_check_is_resource}
            }
        }
    },
    {
        .name = "Incantation",
        .type = RQ_CMD_INCANTATION,
        .handler = &request_handler_cmd_incantation,
        .time_limit = 0,
        .requirements = (request_requirements_t [])
        {
            {
                .client_type    = CLIENT_DRONE,
                .arg_number     = 0,
                .arg_checkers   = (request_arg_checker_t []) {NULL}

            }
        }
    },
    {
        .name = "msz",
        .type = RQ_MAP_SIZE,
        .handler = &request_handler_gui_map_size,
        .time_limit = 0,
        .requirements = (request_requirements_t [])
        {
            {
                .client_type    = CLIENT_SPECTATOR,
                .arg_number     = 0,
                .arg_checkers   = (request_arg_checker_t []) {NULL}

            }
        }
    },
    {
        .name = "bct",
        .type = RQ_TILE_CONTENT,
        .handler = &request_handler_gui_tile_content,
        .time_limit = 0,
        .requirements = (request_requirements_t [])
        {
            {
                .client_type    = CLIENT_SPECTATOR,
                .arg_number     = 2,
                .arg_checkers   = (request_arg_checker_t []){
                    &request_arg_check_is_positive_int,
                    &request_arg_check_is_positive_int
                }
            }
        }
    },
    {
        .name = "mct",
        .type = RQ_MAP_CONTENT,
        .handler = &request_handler_gui_map_content,
        .time_limit = 0,
        .requirements = (request_requirements_t [])
        {
            {
                .client_type    = CLIENT_SPECTATOR,
                .arg_number     = 0,
                .arg_checkers   = (request_arg_checker_t []) {NULL}

            }
        }
    },
    {
        .name = "tna",
        .type = RQ_TEAM_NAMES,
        .handler = &request_handler_gui_team_names,
        .time_limit = 0,
        .requirements = (request_requirements_t [])
        {
            {
                .client_type    = CLIENT_SPECTATOR,
                .arg_number     = 0,
                .arg_checkers   = (request_arg_checker_t []) {NULL}

            }
        }
    },
    {
        .name = "ppo",
        .type = RQ_PLAYER_POSITION,
        .handler = &request_handler_gui_player_position,
        .time_limit = 0,
        .requirements = (request_requirements_t [])
        {
            {
                .client_type    = CLIENT_SPECTATOR,
                .arg_number     = 1,
                .arg_checkers   = (request_arg_checker_t [])
                    {&request_arg_check_is_positive_int}
            }
        }
    },
    {
        .name = "pst",
        .type = RQ_PLAYER_STATS,
        .handler = &request_handler_gui_player_stats,
        .time_limit = 0,
        .requirements = (request_requirements_t [])
        {
            {
                .client_type    = CLIENT_SPECTATOR,
                .arg_number     = 1,
                .arg_checkers   = (request_arg_checker_t [])
                    {&request_arg_check_is_positive_int}
            }
        }
    },
    {
        .name = "sgt",
        .type = RQ_TIME_UNIT_REQUEST,
        .handler = &request_handler_gui_time_unit_request,
        .time_limit = 0,
        .requirements = (request_requirements_t [])
        {
            {
                .client_type    = CLIENT_SPECTATOR,
                .arg_number     = 0,
                .arg_checkers   = (request_arg_checker_t []) {NULL}
            }
        }
    },
};

const size_t request_info_map_size =
    sizeof(request_info_map) / sizeof(request_info_map[0]);
