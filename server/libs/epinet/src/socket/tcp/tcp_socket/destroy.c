/*
** EPITECH PROJECT, 2021
** epinet
** File description:
** destroy
*/

#include <epinet/tcp_socket.h>

void tcp_socket_destroy(tcp_socket_t *socket)
{
    socket_destroy(SOCKET(socket));
}
