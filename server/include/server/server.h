/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <stdbool.h>

#include <mylist.h>

#include "arguments.h"

#include "network/network.h"
#include "simulation/simulation.h"

#define SERVER_EXIT     84
#define SERVER_ERROR    1
#define SERVER_SUCCESS  0

typedef size_t frequency_t;

typedef struct server_s
{
    network_t           n;
    simulation_t        s;
    ptr_list_t *        clients;
    bool                is_running;
    frequency_t         freq;
} server_t;

int server_launch(const arguments_t *args);

int server_start(const arguments_t *args, server_t *s);
void server_stop(server_t *s);

int server_run(server_t *s);
void server_handle_clients_in(server_t *s);
void server_handle_clients_out(server_t *s);

#endif /* !SERVER_H_ */
