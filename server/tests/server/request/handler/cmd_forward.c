/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** cmd_forward
*/

#include <criterion/criterion.h>
#include <string.h>

#include "server/request/handler.h"
#include "server/request/request.h"

Test(request_handler_cmd_forward, simple_go_forward)
{
    client_t *client = client_create();
    request_t *request = request_parse_from_input("Forward", CLIENT_DRONE);
    arguments_t *args = arguments_create();
    server_t server;
    int status = server_start(args, &server);

    client_to_drone(client, drone_create(VEC2U(0, 0), false));
    cr_assert(status == SERVER_SUCCESS);
    cr_assert(client->drone->pos.x == 0);
    cr_assert(client->drone->pos.y == 0);
    client->drone->facing_direction = RIGHT;
    request_handler_cmd_forward(&server, client, request);
    cr_assert(client->drone->pos.x == 1);
    cr_assert(client->drone->pos.y == 0);
    server_stop(&server);
    arguments_destroy(args);
}

Test(request_handler_cmd_forward, simple_go_other_side_of_map)
{
    client_t *client = client_create();
    request_t *request = request_parse_from_input("Forward", CLIENT_DRONE);
    arguments_t *args = arguments_create();
    server_t server;
    int status = server_start(args, &server);

    client_to_drone(client, drone_create(VEC2U(0, 0), false));
    cr_assert(status == SERVER_SUCCESS);
    cr_assert(client->drone->pos.x == 0);
    cr_assert(client->drone->pos.y == 0);
    client->drone->facing_direction = LEFT;
    request_handler_cmd_forward(&server, client, request);
    cr_assert(client->drone->pos.x == 9);
    cr_assert(client->drone->pos.y == 0);
    server_stop(&server);
    arguments_destroy(args);
}
