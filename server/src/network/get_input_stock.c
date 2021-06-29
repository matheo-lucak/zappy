/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace) [WSL: Ubuntu]
** File description:
** get_input_stock
*/

#include <my.h>
#include <epinet.h>

#include "server/client.h"

static const size_t READ_SIZE = 4096;

socket_status_t network_get_input_stock(client_t *c)
{
    char buffer[READ_SIZE + 1];
    size_t nb_bytes = 0;
    int status = 0;

    status = tcp_socket_receive(c->socket, buffer, READ_SIZE, &nb_bytes);
    if (status != SOCKET_DONE && status != SOCKET_PARTIAL)
        return status;
    buffer[nb_bytes] = '\0';
    c->input_stock = my_str_cat(c->input_stock, buffer, true, false);
    return SOCKET_DONE;
}
