/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** network
*/

#ifndef ZAPPY_NETWORK_H_
#define ZAPPY_NETWORK_H_

#include <epinet.h>

#include "arguments.h"
#include "server/client.h"

#define NETWORK_EXIT    84
#define NETWORK_ERROR   1
#define NETWORK_SUCCESS 0

typedef struct network_s
{
    socket_selector_t * selector;
    tcp_listener_t *    listener;
    unsigned            client_next_id;
} network_t;

/**
* @brief Initializes a network structure by assigning
*        a 'selector', 'listener', and a default 'client_next_id'.
*
* @param args The specificities of the network initialization.
* @param n A pointer to the network structure to initialize.
* @return int NETWORK_SUCCESS on success,
*             otherwise returns other NETWORK specific macros.
*/
int network_start(const arguments_t *args, network_t *n);

/**
* @brief Releases memory previous allocated to a network structure.
*
* @param n The network structure to release memory from.
*/
void network_stop(network_t *n);

/**
* @brief Reads new bytes from the socket of a client
*
* @param c The client to read new bytes from.
* @return socket_status_t The status of the socket.
*/
socket_status_t network_get_input_stock(client_t *c);

#endif /* !ZAPPY_NETWORK_H_ */
