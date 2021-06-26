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

#include "logger/logger.h"

#define SERVER_EXIT     84
#define SERVER_ERROR    1
#define SERVER_SUCCESS  0

typedef size_t frequency_t;

typedef struct server_s
{
    network_t           n;
    simulation_t        sim;
    ptr_list_t *        clients;
    bool                is_running;
    frequency_t         freq;
} server_t;

int server_launch(const arguments_t *args);

int server_start(const arguments_t *args, server_t *s);
void server_stop(server_t *s);

int server_run(server_t *s);

void network_handle_clients_in(server_t *s);
int network_handle_clients_out(server_t *s);
void network_handle_client_connection(server_t *s);

void server_handle_request(server_t *s);

void server_remove_client(server_t *s, client_t *client);

client_t *server_find_client_from_drone(server_t *s, drone_t *drone);

#endif /* !SERVER_H_ */
