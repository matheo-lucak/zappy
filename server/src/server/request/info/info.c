/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** info
*/

#include "server/request/info.h"

const request_info_t request_info_map[] =
{
    {.name = "Forward",     .type = RQ_CMD_FORWARD,         .time_limit = 7},
    {.name = "Right",       .type = RQ_CMD_RIGHT,           .time_limit = 7},
    {.name = "Left",        .type = RQ_CMD_LEFT,            .time_limit = 7},
    {.name = "Look",        .type = RQ_CMD_LOOK,            .time_limit = 7},
    {.name = "Inventory",   .type = RQ_CMD_INVENTORY,       .time_limit = 1},
    {.name = "Broadcast",   .type = RQ_CMD_BROADCAST,       .time_limit = 7},
    {.name = "Connect_nbr", .type = RQ_CMD_CONNECT_NBR,     .time_limit = 0},
    {.name = "Fork",        .type = RQ_CMD_FORK,            .time_limit = 42},
    {.name = "Eject",       .type = RQ_CMD_EJECT,           .time_limit = 7},
    {.name = "Take",        .type = RQ_CMD_TAKE_OBJECT,     .time_limit = 7},
    {.name = "Set",         .type = RQ_CMD_SET_OBJECT,      .time_limit = 7},
    {.name = "Incantation", .type = RQ_CMD_INCANTATION,     .time_limit = 300},

    {.name = "msz",         .type = RQ_MAP_SIZE,            .time_limit = 0},
    {.name = "bct",         .type = RQ_TILE_CONTENT,        .time_limit = 0},
    {.name = "mct",         .type = RQ_MAP_CONTENT,         .time_limit = 0},
    {.name = "tna",         .type = RQ_TEAM_NAMES,          .time_limit = 0},
    {.name = "ppo",         .type = RQ_PLAYER_POSITION,     .time_limit = 0},
    {.name = "plv",         .type = RQ_PLAYER_LEVEL,        .time_limit = 0},
    {.name = "pin",         .type = RQ_PLAYER_INVENTORY,    .time_limit = 0},
    {.name = "sgt",         .type = RQ_TIME_UNIT_REQUEST,   .time_limit = 0},
    {.name = "sst",         .type = RQ_TIME_UNIT_MODIF,     .time_limit = 0},
};

const size_t request_info_map_size =
    sizeof(request_info_map) / sizeof(request_info_map[0]);
