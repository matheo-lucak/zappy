/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** request
*/

#ifndef ZAPPY_REQUEST_H_
#define ZAPPY_REQUEST_H_

#include <mylist/string_list.h>
#include "server/client.h"

#include "server/client.h"
#include "server/request/handler.h"
#include "server/request/checker.h"

#define RQ_SEPARATORS " "
#define RQ_DELIMITER  '\n'

#define RQ_MAGIC_GUI  "0xea83f3_gui_application"

typedef enum request_type_e
{
    RQ_DEFAULT,

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
    RQ_PLAYER_STATS,
    RQ_PLAYER_INVENTORY,
    RQ_TIME_UNIT_REQUEST,
    RQ_TIME_UNIT_MODIF,
} request_type_t;

typedef struct request_s
{
    request_type_t           type;
    char *                   name;
    string_list_t *          arguments;
    int                      time_limit;
    request_requirements_t * requirements;
    request_handler_t        handler;
    bool                     is_valid;
} request_t;

/**
* @brief Instantiates a new request.
*
* @return request_t* The pointer to the newly allocated request.
*/
request_t *request_create(void);

/**
* @brief Releases memory previously allocated to a request.
*
* @param request The request to release memory from.
*/
void request_destroy(request_t *request);

/**
* @brief Gets a new input from a client,
*        stores the excess bytes in its input_stock.
*
* @param c The client to get the input from.
* @return char* The newly allocated received input.
*/
char *request_get_input(client_t *c);

/**
* @brief Get a new request parsed from the given input
*
* If the parsing do not succeed, an request object is still allocatedand return
* but it's is_valid internal value is set to false
*
* @param input The given input coming from a client
* @param type The type of the client from which the input comes.
* @return request_t* A new requested fill with info extracted from the input.
*/
request_t *request_parse_from_input(char *input, client_type_t type);

#endif /* !ZAPPY_REQUEST_H_ */
