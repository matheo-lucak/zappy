/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** command_request
*/

#ifndef COMMAND_REQUEST_H_
#define COMMAND_REQUEST_H_

typedef enum command_request_type_e
{
    CMD_RQ_FORWARD,
    CMD_RQ_RIGHT,
    CMD_RQ_LEFT,
    CMD_RQ_LOOK,
    CMD_RQ_INVENTORY,
    CMD_RQ_BROADCAST,
    CMD_RQ_CONNECT_NBR,
    CMD_RQ_FORK,
    CMD_RQ_EJECT,
    CMD_RQ_TAKE_OBJECT,
    CMD_RQ_SET_OBJECT,
    CMD_RQ_INCANTATION,
} command_request_type_t;

typedef struct command_info_s
{
    char *                  name;
    command_request_type_t  type;
    int                     time_limit;
} command_request_info_t;

//extern const command_info_t COMMAND_INFOS[];

static const command_request_info_t COMMAND_INFOS[] = {
    {.name = "Forward",     .type = CMD_RQ_FORWARD,     .time_limit = 7},
    {.name = "Right",       .type = CMD_RQ_RIGHT,       .time_limit = 7},
    {.name = "Left",        .type = CMD_RQ_LEFT,        .time_limit = 7},
    {.name = "Look",        .type = CMD_RQ_LOOK,        .time_limit = 7},
    {.name = "Inventory",   .type = CMD_RQ_INVENTORY,   .time_limit = 1},
    {.name = "Broadcast",   .type = CMD_RQ_BROADCAST,   .time_limit = 7},
    {.name = "Connect_nbr", .type = CMD_RQ_CONNECT_NBR, .time_limit = 0},
    {.name = "Fork",        .type = CMD_RQ_FORK,        .time_limit = 42},
    {.name = "Eject",       .type = CMD_RQ_EJECT,       .time_limit = 7},
    {.name = "Take",        .type = CMD_RQ_TAKE_OBJECT, .time_limit = 7},
    {.name = "Set",         .type = CMD_RQ_SET_OBJECT,  .time_limit = 7},
    {.name = "Incantation", .type = CMD_RQ_INCANTATION, .time_limit = 300},
};

typedef struct command_request_s
{
    command_request_type_t type;
    char parameter[256];
} command_request_t;

#endif /* !COMMAND_REQUEST_H_ */
