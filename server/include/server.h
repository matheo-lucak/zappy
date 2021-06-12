/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include "arguments.h"

#include <epinet.h>
#include <mylist.h>

typedef struct server_s
{
    socket_selector_t * selector;
    tcp_listener_t *    listener;
    list_t *            clients;
} server_t;

#endif /* !SERVER_H_ */
