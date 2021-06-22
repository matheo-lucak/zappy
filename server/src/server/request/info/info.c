/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** info
*/

#include "server/request/info.h"

const request_info_t request_info_map[] =
{
    /* Drone COMMANDS*/

    {
        .name = "Forward",
        .type = RQ_CMD_FORWARD,
        .handler = &request_handler_cmd_forward,
        .time_limit = 7
    },
    {
        .name = "Right",
        .type = RQ_CMD_RIGHT,
        .handler = &request_handler_cmd_right,
        .time_limit = 7
    },
    {
        .name = "Left",
        .type = RQ_CMD_LEFT,
        .handler = &request_handler_cmd_left,
        .time_limit = 7
    },
    {
        .name = "Look",
        .type = RQ_CMD_LOOK,
        .handler = &request_handler_cmd_look,
        .time_limit = 7
    },
    {
        .name = "Inventory",
        .type = RQ_CMD_INVENTORY,
        .handler = &request_handler_cmd_inventory,
        .time_limit = 1
    },
    {
        .name = "Broadcast",
        .type = RQ_CMD_BROADCAST,
        .handler = &request_handler_cmd_broadcast,
        .time_limit = 7
    },
    {
        .name = "Connect_nbr",
        .type = RQ_CMD_CONNECT_NBR,
        .handler = &request_handler_cmd_connect_nbr,
        .time_limit = 0
    },
    {
        .name = "Fork",
        .type = RQ_CMD_FORK,
        .handler = &request_handler_cmd_fork,
        .time_limit = 42
    },
    {
        .name = "Eject",
        .type = RQ_CMD_EJECT,
        .handler = &request_handler_cmd_eject,
        .time_limit = 7
    },
    {
        .name = "Take",
        .type = RQ_CMD_TAKE_OBJECT,
        .handler = &request_handler_cmd_take,
        .time_limit = 7
    },
    {
        .name = "Set",
        .type = RQ_CMD_SET_OBJECT,
        .handler = &request_handler_cmd_set,
        .time_limit = 7
    },
    {
        .name = "Incantation",
        .type = RQ_CMD_INCANTATION,
        .handler = &request_handler_cmd_incantation,
        .time_limit = 300
    },

    /* GUI COMMANDS*/

    {
        .name = "msz",
        .type = RQ_MAP_SIZE,
        .handler = &request_handler_gui_map_size,
        .time_limit = 0
    },
    {
        .name = "bct",
        .type = RQ_TILE_CONTENT,
        .handler = &request_handler_gui_tile_content,
        .time_limit = 0
    },
    {
        .name = "mct",
        .type = RQ_MAP_CONTENT,
        .handler = &request_handler_gui_map_content,
        .time_limit = 0
    },
    {
        .name = "tna",
        .type = RQ_TEAM_NAMES,
        .handler = &request_handler_gui_team_names,
        .time_limit = 0
    },
    {
        .name = "ppo",
        .type = RQ_PLAYER_POSITION,
        .handler = &request_handler_gui_player_position,
        .time_limit = 0
    },
    {
        .name = "plv",
        .type = RQ_PLAYER_LEVEL,
        .handler = &request_handler_gui_player_level,
        .time_limit = 0
    },
    {
        .name = "pin",
        .type = RQ_PLAYER_INVENTORY,
        .handler = &request_handler_gui_player_inventory,
        .time_limit = 0
    },
    {
        .name = "sgt",
        .type = RQ_TIME_UNIT_REQUEST,
        .handler = &request_handler_gui_time_unit_request,
        .time_limit = 0
    },
    {
        .name = "sst",
        .type = RQ_TIME_UNIT_MODIF,
        .handler = &request_handler_gui_time_unit_modif,
        .time_limit = 0
    },
};

const size_t request_info_map_size =
    sizeof(request_info_map) / sizeof(request_info_map[0]);
