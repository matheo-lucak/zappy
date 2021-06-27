/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** main
*/

#include "arg_parser.h"
#include "server/server.h"

int main(int ac, char **av)
{
    client_t *client = client_create();
    request_t *request = request_parse_from_input(strdup("Forward"), CLIENT_DRONE);
    arguments_t args = arguments_default_values();
    server_t server;
    int status = server_start(&args, &server);

    client_to_drone(client, drone_create(0, 0, false));

//    cr_assert(status == SERVER_SUCCESS);
//    cr_assert(client->drone->x == 0);
//    cr_assert(client->drone->y == 0);
    client->drone->facing_direction = RIGHT;
    request_handler_cmd_forward(&server, client, request);
//    cr_assert(client->drone->x == 1);
//    cr_assert(client->drone->y == 0);
    server_stop(&server);

//    arguments_t args = arguments_default_values();
//
//    if (parse_arguments(ac, av, &args))
//        return SERVER_EXIT;
//    return server_launch(&args);
}
