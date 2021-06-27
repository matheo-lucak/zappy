/*
** EPITECH PROJECT, 2021
** server
** File description:
** destroy
*/

#include <stdlib.h>

#include "server/response/response.h"

void response_destroy(response_t *response)
{
    if (!response)
        return;
    free(response->data);
    free(response);
}
