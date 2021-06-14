/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** info
*/

#ifndef INFO_H_
#define INFO_H_

#include "server/request/request.h"

typedef struct request_info_s
{
    char *                  name;
    request_type_t          type;
    int                     time_limit;
} request_info_t;

const request_info_t *request_get_info_from_name(char *name);

extern const request_info_t request_info_map[];
extern const size_t request_info_map_size;

#endif /* !INFO_H_ */
