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
/// \brief Clients structure
///
/// This represents either a connected player
/// The client can be 'unknown', a 'drone' or a 'spectator'
/// By default a client is 'unkown' an become 'drone' of 'spectator'
/// by asking to the server with :
/// The team name to join; to become a 'drone'
/// The command "GUI" to become a 'specator'
///
/// A client 'drone' must have its drone member to be allocated
///
/// Requests:
/// A client can't exceed CLIENT_MAX_PENDING_REQUEST requests in pending.
/// Beyond that, incoming requests are not taken in account
////////////////////////////////////////////////////////////////////////////////
typedef struct client_s
{
    client_type_t   type;
    tcp_socket_t *  socket;
    char *          input_stock;
    drone_t *       drone;
    ptr_list_t *    pending_requests;
    ptr_list_t *    pending_responses;
} client_t;

typedef struct request_s    request_t;
typedef struct response_s   response_t;

client_t *client_create(void);
void client_destroy(client_t *client);

void client_to_drone(client_t *client, drone_t *drone);
void client_to_spectator(client_t *client);

void client_add_request(client_t *client, request_t *request);
void client_add_response(client_t *client, response_t *response);

#endif /* !CLIENT_H_ */
