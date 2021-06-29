/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** request_checker
*/

#ifndef ZAPPY_REQUEST_CHECKER_H_
#define ZAPPY_REQUEST_CHECKER_H_

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

/**
* @brief Security after a request has been initialized.
*
* @param client The client making the request.
* @param request The request associated.
* @return true If the requierements are met.
* @return false If the requierements aren't met.
*/
bool request_checker(client_t *client, request_t *request);

/**
* @brief Default argument checking value for requests, returns true.
*
* @param arg The default argument to send, purely superficial here.
* @return true Always.
*/
bool request_arg_no_check(char *arg);

/**
* @brief Checks if the given argument contains
*        the value of an existing resource.
*
* @param arg The given argument to check onto.
* @return true If it matches with an existing resource name.
* @return false If it doesn't match with an existing resource name.
*/
bool request_arg_check_is_resource(char *arg);

/**
* @brief Checks if the given argument contains a positive integer.
*
* @param arg The given argument to check onto.
* @return true If it contains a positive integer.
* @return false If it doesn't contain a positive integer.
*/
bool request_arg_check_is_positive_int(char *arg);

#endif /* !ZAPPY_REQUEST_CHECKER_H_ */
