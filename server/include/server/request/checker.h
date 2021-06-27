/*
** EPITECH PROJECT, 2021
** server
** File description:
** checker
*/

#ifndef CHECKER_H_
#define CHECKER_H_

#include "server/client.h"

#define RQ_REQUIRE_NO_ARG -1
#define RQ_REQUIRE_NO_CLIENT_TYPE -1

typedef struct request_s request_t;

typedef bool (*request_arg_checker_t)(char *);

typedef struct request_requirements_s
{
    int                     client_type;
    int                     arg_number;
    request_arg_checker_t * arg_checkers;
} request_requirements_t;

bool request_checker(client_t *client, request_t *request);

bool request_arg_no_check(char *);
bool request_arg_check_is_resource(char *);
bool request_arg_check_is_positive_int(char *);

#endif /* !CHECKER_H_ */
