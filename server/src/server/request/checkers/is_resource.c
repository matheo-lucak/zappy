/*
** EPITECH PROJECT, 2021
** server
** File description:
** is_resource
*/

#include <stdbool.h>

#include "simulation/resources.h"

bool request_arg_check_is_resource(char *arg)
{
    return !!resource_get_info_from_name(arg);
}
