/*
** EPITECH PROJECT, 2021
** server
** File description:
** add_response
*/

#include "server/response/response.h"
#include "server/client.h"

void client_add_response(client_t *client, response_t *response)
{
    if (!client || !response)
        return;
    ptr_list_push_back(client->pending_responses, response);
}
