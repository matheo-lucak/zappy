/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** request_info
*/

#ifndef ZAPPY_REQUEST_INFO_H_
#define ZAPPY_REQUEST_INFO_H_

#include "server/request/request.h"
#include "server/request/handler.h"

typedef struct request_info_s
{
    char *                   name;
    request_type_t           type;
    request_handler_t        handler;
    int                      time_limit;
    request_requirements_t * requirements;
} request_info_t;

/**
* @brief Gets a request default information upon giving the request name.
*
* @param name The request name.
* @return const request_info_t* A pointer to a request_info structure
*                               that contains specificities on the request.
*                               Upon not finding, returns a NULL pointer.
*/
const request_info_t *request_get_info_from_name(char *name);

extern const request_info_t request_info_map[];
extern const size_t request_info_map_size;
extern const request_info_t default_request_info;

#endif /* !ZAPPY_REQUEST_INFO_H_ */
