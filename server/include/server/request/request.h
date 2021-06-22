/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** request
*/

#ifndef REQUEST_H_
#define REQUEST_H_

#include <mylist/string_list.h>

#include"server/request/handler.h"

#define RQ_SEPARATORS " "
#define RQ_DELIMITER '\n'

typedef enum request_type_e
{
    RQ_CMD_FORWARD,
    RQ_CMD_RIGHT,
    RQ_CMD_LEFT,
    RQ_CMD_LOOK,
    RQ_CMD_INVENTORY,
    RQ_CMD_BROADCAST,
    RQ_CMD_CONNECT_NBR,
    RQ_CMD_FORK,
    RQ_CMD_EJECT,
    RQ_CMD_TAKE_OBJECT,
    RQ_CMD_SET_OBJECT,
    RQ_CMD_INCANTATION,

    RQ_MAP_SIZE,
    RQ_TILE_CONTENT,
    RQ_MAP_CONTENT,
    RQ_TEAM_NAMES,
    RQ_PLAYER_POSITION,
    RQ_PLAYER_LEVEL,
    RQ_PLAYER_INVENTORY,
    RQ_TIME_UNIT_REQUEST,
    RQ_TIME_UNIT_MODIF,
} request_type_t;

typedef struct request_s
{
    bool                is_valid;
    request_type_t      type;
    int                 time_limit;
    string_list_t *     arguments;
    request_handler_t   handler;
} request_t;

request_t *request_create(void);
void request_destroy(request_t *request);

request_t *request_parse_from_input(char *input);

#endif /* !REQUEST_H_ */
