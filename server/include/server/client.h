/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include <epinet/tcp_socket.h>

#include "simulation/drone.h"

////////////////////////////////////////////////////////////////////////////////
/// \brief Clients structure
///
/// This represents either a connected player, called a drone, or a spectator.
/// A Specator is simply a client_t with its .drone set to NULL
/// A Drone a client_t with its .drone set to a valid address
////////////////////////////////////////////////////////////////////////////////
typedef struct client_s
{
    tcp_socket_t *  socket;
    char *          input_stock;
    drone_t *       drone;
} client_t;

client_t *client_create(void);
void client_destroy(client_t *client);

void client_set_drone(client_t *client, drone_t *drone);

bool client_is_spectator(client_t *client);
bool client_is_drone(client_t *client);

#endif /* !CLIENT_H_ */
