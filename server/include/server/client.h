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

typedef struct client_s
{
    tcp_socket_t *  socket;
    drone_t *       drone;
} client_t;

client_t *client_create(void);
void client_destroy(client_t *c);

#endif /* !CLIENT_H_ */
