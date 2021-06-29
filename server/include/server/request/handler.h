/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** request_handler
*/

#ifndef ZAPPY_REQUEST_HANDLER_H_
#define ZAPPY_REQUEST_HANDLER_H_

#include "server/server.h"

typedef struct request_s request_t;

typedef void (*request_handler_t)(
    server_t *,
    client_t *,
    request_t *
);

///////////////////////////////
// Universal client requests //
///////////////////////////////

/**
* @brief Handles a default request bound to a client.
*        Instantiates a response and stores it in the client's
*        pending responses queue.
*/
void request_handler_default(server_t *s, client_t *c, request_t *r);

////////////////////////
// AI client requests //
////////////////////////

/**
* @brief Handles a forward request bound to a client.
*        Instantiates a response and stores it in the client's
*        pending responses queue.
*/
void request_handler_cmd_forward(server_t *, client_t *, request_t *);

/**
* @brief Handles a right request bound to a client.
*        Instantiates a response and stores it in the client's
*        pending responses queue.
*/
void request_handler_cmd_right(server_t *, client_t *, request_t *);

/**
* @brief Handles a left request bound to a client.
*        Instantiates a response and stores it in the client's
*        pending responses queue.
*/
void request_handler_cmd_left(server_t *, client_t *, request_t *);

/**
* @brief Handles a look request bound to a client.
*        Instantiates a response and stores it in the client's
*        pending responses queue.
*/
void request_handler_cmd_look(server_t *, client_t *, request_t *);

/**
* @brief Handles an inventory request bound to a client.
*        Instantiates a response and stores it in the client's
*        pending responses queue.
*/
void request_handler_cmd_inventory(server_t *, client_t *, request_t *);

/**
* @brief Handles a broadcast request bound to a client.
*        Instantiates a response and stores it in the client's
*        pending responses queue.
*        Instantiates responses for all other clients existing and
*        store them in their respective pending responses queues.
*/
void request_handler_cmd_broadcast(server_t *, client_t *, request_t *);

/**
* @brief Handles a connect_nbr request bound to a client.
*        Instantiates a response and stores it in the client's
*        pending responses queue.
*/
void request_handler_cmd_connect_nbr(server_t *, client_t *, request_t *);

/**
* @brief Handles a fork request bound to a client.
*        Instantiates a response and stores it in the client's
*        pending responses queue.
*/
void request_handler_cmd_fork(server_t *, client_t *, request_t *);

/**
* @brief Handles an eject request bound to a client.
*        Instantiates a response and stores it in the client's
*        pending responses queue.
*        Instantiates responses for all other clients on the tile
*        where the drone of the client is, store them in their
*        respective pending responses queues.
*/
void request_handler_cmd_eject(server_t *, client_t *, request_t *);

/**
* @brief Handles a take request bound to a client.
*        Instantiates a response and stores it in the client's
*        pending responses queue.
*/
void request_handler_cmd_take(server_t *, client_t *, request_t *);

/**
* @brief Handles a set request bound to a client.
*        Instantiates a response and stores it in the client's
*        pending responses queue.
*/
void request_handler_cmd_set(server_t *, client_t *, request_t *);

/**
* @brief Handles an incantation request bound to a client.
*        Instantiates a response and stores it in the client's
*        pending responses queue.
*/
void request_handler_cmd_incantation(server_t *, client_t *, request_t *);

/////////////////////////
// GUI client requests //
/////////////////////////

/**
* @brief Handles a map_size request bound to a client.
*        Instantiates a response and stores it in the client's
*        pending responses queue.
*/
void request_handler_gui_map_size(server_t *, client_t *, request_t *);

/**
* @brief Handles a tile_content request bound to a client.
*        Instantiates a response and stores it in the client's
*        pending responses queue.
*/
void request_handler_gui_tile_content(server_t *, client_t *, request_t *);

/**
* @brief Handles a map_content request bound to a client.
*        Instantiates a response and stores it in the client's
*        pending responses queue.
*/
void request_handler_gui_map_content(server_t *, client_t *, request_t *);

/**
* @brief Handles a team_names request bound to a client.
*        Instantiates a response and stores it in the client's
*        pending responses queue.
*/
void request_handler_gui_team_names(server_t *, client_t *, request_t *);

/**
* @brief Handles a player_position request bound to a client.
*        Instantiates a response and stores it in the client's
*        pending responses queue.
*/
void request_handler_gui_player_position(server_t *, client_t *, request_t *);

/**
* @brief Handles a player_level request bound to a client.
*        Instantiates a response and stores it in the client's
*        pending responses queue.
*/
void request_handler_gui_player_level(server_t *, client_t *, request_t *);

/**
* @brief Handles a player_inventory request bound to a client.
*        Instantiates a response and stores it in the client's
*        pending responses queue.
*/
void request_handler_gui_player_inventory(server_t *, client_t *, request_t *);

/**
* @brief Handles a time_unit request bound to a client.
*        Instantiates a response and stores it in the client's
*        pending responses queue.
*/
void request_handler_gui_time_unit_request(server_t *, client_t *, request_t *);

/**
* @brief Handles a time_unit_modif request bound to a client.
*        Instantiates a response and stores it in the client's
*        pending responses queue.
*/
void request_handler_gui_time_unit_modif(server_t *, client_t *, request_t *);

#endif /* !ZAPPY_REQUEST_HANDLER_H_ */
