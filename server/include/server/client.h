/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include <epinet/tcp_socket.h>
#include <mylist/ptr_list.h>

#include "simulation/drone.h"

#define CLIENT_MAX_PENDING_REQUEST  10

typedef enum client_type_e
{
    CLIENT_UNKNOWN      = 0b00000001,
    CLIENT_DRONE        = 0b00000010,
    CLIENT_SPECTATOR    = 0b00000100
} client_type_t;

////////////////////////////////////////////////////////////////////////////////
/// \brief This represents a connected player.
/// The client can either be described as 'unknown', 'drone' or 'spectator'.
/// By default a client is 'unknown' and becomes a 'drone' or a 'spectator'
/// by asking to the server with:
/// The name of the team to join; to become a 'drone'.
/// The command "GUI" to become a 'spectator'.
///
/// A client 'drone' must have its drone member allocated.
///
/// Requests:
/// A client can't exceed CLIENT_MAX_PENDING_REQUEST pending requests.
/// Beyond that, incoming requests are not taken into account.
///
/// A client can be blocked.
/// It means that the client can't treat its pending requests
/// until it is unblocked.
////////////////////////////////////////////////////////////////////////////////
typedef struct client_s
{
    unsigned       id;
    client_type_t  type;
    bool           alive;
    bool           blocked;
    tcp_socket_t * socket;
    char *         input_stock;
    drone_t *      drone;
    ptr_list_t *   pending_requests;
    ptr_list_t *   pending_responses;
} client_t;

typedef struct request_s  request_t;
typedef struct response_s response_t;

/**
* @brief Creates a newly allocated client.
*
* Once the object is returned, all the inside data is valid and well allocated.
*
* @return response_t* A pointer to the newly allocated client.
* @return NULL in case of failure.
*/
client_t *client_create(void);

/**
* @brief Releases memory previously allocated to a client.
*
* @param client The client to release memory from.
*/
void client_destroy(client_t *client);

/**
* @brief Blocks a client.
*
* @param client The client to block.
*/
void client_block(client_t *client);

/**
* @brief Unblocks a client.
*
* @param client The client to unblock.
*/
void client_unblock(client_t *client);

/**
* @brief Formates the client to control a drone.
*
* @param client The client to change.
* @param drone The drone given to the client.
*/
void client_to_drone(client_t *client, drone_t *drone);

/**
* @brief Formates the client to be a spectator.
*
* @param client The client to change.
*/
void client_to_spectator(client_t *client);

/**
* @brief Adds response to the request queue of a client.
*
* The request is added to the end of the queue
*
* @param client The client.
* @param request The request to add.
*/
void client_add_request(client_t *client, request_t *request);

/**
* @brief Adds response to the response queue of a client.
*
* The response is added to the end of the queue.
*
* @param client The client.
* @param response The response to add.
*/
void client_add_response(client_t *client, response_t *response);

#endif /* !CLIENT_H_ */
