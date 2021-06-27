/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** network
*/

#ifndef NETWORK_H_
#define NETWORK_H_

#include <epinet.h>

#include "arguments.h"

#define NETWORK_EXIT     84
#define NETWORK_ERROR    1
#define NETWORK_SUCCESS  0

typedef struct network_s
{
    socket_selector_t * selector;
    tcp_listener_t *    listener;
    unsigned            client_next_id;
} network_t;

int network_start(const arguments_t *args, network_t *n);
void network_stop(network_t *n);

#endif /* !NETWORK_H_ */
