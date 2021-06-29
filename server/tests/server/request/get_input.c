/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** get_input
*/

#include <fcntl.h>
#include <unistd.h>
#include <criterion/criterion.h>

#include "server/request/request.h"

Test(request_get_input, simple_input_from_file)
{
    const char *filepath = "tests/server/request/tests_files/simple_input";
    char *received_input = NULL;
    client_t client = {0};

    client.socket = malloc(sizeof(client.socket));
    client.socket->socket = open(filepath, O_RDONLY);
    cr_assert(client.socket->socket >= 0);
    received_input = request_get_input(&client);
    cr_expect_str_eq(received_input, "TEST");
    close(client.socket->socket);
    free(client.socket);
    free(received_input);
}

Test(request_get_input, input_from_file_no_return)
{
    const char *filepath = "tests/server/request/tests_files/input_no_ret";
    char *received_input = NULL;
    client_t client = {0};

    client.socket = malloc(sizeof(client.socket));
    client.socket->socket = open(filepath, O_RDONLY);
    cr_assert(client.socket->socket >= 0);
    received_input = request_get_input(&client);
    cr_expect_str_eq(received_input, "TEST");
    close(client.socket->socket);
    free(client.socket);
    free(received_input);
}

Test(request_get_input, several_lines)
{
    const char *filepath = "tests/server/request/tests_files/several_lines";
    char *received_input = NULL;
    client_t client = {0};

    client.socket = malloc(sizeof(client.socket));
    client.socket->socket = open(filepath, O_RDONLY);
    cr_assert(client.socket->socket >= 0);
    received_input = request_get_input(&client);
    cr_expect_str_eq(received_input, "TEST");
    free(received_input);
    received_input = request_get_input(&client);
    cr_expect_str_eq(received_input, "Tester");
    free(received_input);
    received_input = request_get_input(&client);
    cr_expect_str_eq(received_input, "Testing");
    free(received_input);
    close(client.socket->socket);
    free(client.socket);
}
