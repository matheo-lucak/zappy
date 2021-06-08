/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** map
*/

#include "arg_parser/arg_setter.h"

const arg_setter_map_t argument_setters[] =
{
    {.option = 'p', .setter = arg_setter_port},
    {.option = 'x', .setter = arg_setter_width},
    {.option = 'y', .setter = arg_setter_height},
//    {.option = 'n', .setter = NULL},
    {.option = 'c', .setter = arg_setter_clients_nb},
    {.option = 'f', .setter = arg_setter_frequency},
    {.option = 0, .setter   = NULL},
};