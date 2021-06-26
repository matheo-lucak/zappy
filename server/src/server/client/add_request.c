/*
** EPITECH PROJECT, 2021
** server
** File description:
** add_request
*/

#include "server/request/request.h"
#include "server/client.h"

void client_add_request(client_t *client, request_t *request)
{
    if (!client || !request)
        return;
    ptr_list_push_back(client->pending_requests, request);
}
