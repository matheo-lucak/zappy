/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** cmd_forward
*/

#include <criterion/criterion.h>
#include "server/request/handler.h"
#include "server/request/request.h"

Test(request_handler_cmd_left, simple_go_left_to_down)
{
    client_t *client = client_create();
    request_t *request = request_parse_from_input("Left", CLIENT_DRONE);
    arguments_t *args = arguments_create();
    server_t server;
    int status = server_start(args, &server);

    client_to_drone(client, drone_create(VEC2U(0, 0), false));
    cr_assert(status == SERVER_SUCCESS);
    client->drone->facing_direction = LEFT;
    request_handler_cmd_left(&server, client, request);
    cr_assert(client->drone->facing_direction == DOWN);
    server_stop(&server);
    arguments_destroy(args);
}

Test(request_handler_cmd_left, simple_go_down_to_right)
{
    client_t *client = client_create();
    request_t *request = request_parse_from_input("Left", CLIENT_DRONE);
    arguments_t *args = arguments_create();
    server_t server;
    int status = server_start(args, &server);

    client_to_drone(client, drone_create(VEC2U(0, 0), false));
    cr_assert(status == SERVER_SUCCESS);
    client->drone->facing_direction = DOWN;
    request_handler_cmd_left(&server, client, request);
    cr_assert(client->drone->facing_direction == RIGHT);
    server_stop(&server);
    arguments_destroy(args);
}

Test(request_handler_cmd_left, simple_go_right_to_up)
{
    client_t *client = client_create();
    request_t *request = request_parse_from_input("Left", CLIENT_DRONE);
    arguments_t *args = arguments_create();
    server_t server;
    int status = server_start(args, &server);

    client_to_drone(client, drone_create(VEC2U(0, 0), false));
    cr_assert(status == SERVER_SUCCESS);
    client->drone->facing_direction = RIGHT;
    request_handler_cmd_left(&server, client, request);
    cr_assert(client->drone->facing_direction == UP);
    server_stop(&server);
    arguments_destroy(args);
}

Test(request_handler_cmd_left, simple_go_up_to_left)
{
    client_t *client = client_create();
    request_t *request = request_parse_from_input("Left", CLIENT_DRONE);
    arguments_t *args = arguments_create();
    server_t server;
    int status = server_start(args, &server);

    client_to_drone(client, drone_create(VEC2U(0, 0), false));
    cr_assert(status == SERVER_SUCCESS);
    client->drone->facing_direction = UP;
    request_handler_cmd_left(&server, client, request);
    cr_assert(client->drone->facing_direction == LEFT);
    server_stop(&server);
    arguments_destroy(args);
}

Test(request_handler_cmd_left, simple_go_down_and_walk)
{
    client_t *client = client_create();
    request_t *request = request_parse_from_input("Left", CLIENT_DRONE);
    arguments_t *args = arguments_create();
    server_t server;
    int status = server_start(args, &server);

    client_to_drone(client, drone_create(VEC2U(0, 0), false));
    cr_assert(status == SERVER_SUCCESS);
    client->drone->pos.x = 4;
    client->drone->pos.y = 4;
    client->drone->facing_direction = LEFT;
    request_handler_cmd_left(&server, client, request);
    cr_assert(client->drone->facing_direction == DOWN);
    cr_assert(drone_move(client->drone, server.sim.map));
    cr_assert(client->drone->pos.x == 4);
    cr_assert(client->drone->pos.y == 5);
    server_stop(&server);
    arguments_destroy(args);
}
