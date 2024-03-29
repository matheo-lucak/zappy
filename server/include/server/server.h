/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** server
*/

#ifndef ZAPPY_SERVER_H_
#define ZAPPY_SERVER_H_

#include <stdbool.h>

#include <mylist.h>

#include "arguments.h"

#include "network/network.h"
#include "simulation/simulation.h"

#include "logger/logger.h"

#define SERVER_EXIT    84
#define SERVER_ERROR   1
#define SERVER_SUCCESS 0

typedef size_t frequency_t;

typedef struct server_s
{
    bool         is_running;
    int          status;
    network_t    n;
    simulation_t sim;
    ptr_list_t * clients;
    frequency_t  freq;
} server_t;

int server_launch(const arguments_t *args);

int server_start(const arguments_t *args, server_t *s);
void server_stop(server_t *s);

int server_run(server_t *s);

void network_handle_clients_in(server_t *s);
void network_handle_clients_out(server_t *s);
void network_handle_client_connection(server_t *s);

void network_remove_connection(network_t *n, client_t *c);

void server_handle_request_parsing(server_t *s);
void server_handle_request(server_t *s);

void server_clear_clients(server_t *s);
void server_remove_client(server_t *s, client_t *client);

client_t *server_find_client_from_drone(server_t *s, drone_t *drone);
client_t *server_find_client_from_id(server_t *s, unsigned id);
drone_t *server_find_drone_from_id(server_t *s, unsigned id);

void server_add_notification(server_t *s, response_t *r);

#endif /* !ZAPPY_SERVER_H_ */
