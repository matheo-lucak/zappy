/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** parse
*/

#include <string.h>
#include <criterion/criterion.h>

#include "server/request/request.h"

Test(request_parse_from_input, default_request)
{
    char *input = strdup("TeamName1");
    request_t *request = request_parse_from_input(input, CLIENT_UNKNOWN);

    cr_assert(request);
    cr_assert(request->type == RQ_DEFAULT);
    cr_assert(list_len(request->arguments) == 0);
    cr_assert_str_eq(request->name, "TeamName1");
    free(input);
    request_destroy(request);
}

Test(request_parse_from_input, default_request_w_existing_rq_name)
{
    char *input = strdup("Forward");
    request_t *request = request_parse_from_input(input, CLIENT_UNKNOWN);

    cr_assert(request);
    cr_assert(request->type == RQ_DEFAULT);
    cr_assert(list_len(request->arguments) == 0);
    cr_assert_str_eq(request->name, "Forward");
    free(input);
    request_destroy(request);
}

Test(request_parse_from_input, success_without_arg_1)
{
    char *input = strdup("Forward");
    request_t *request = request_parse_from_input(input, CLIENT_DRONE);

    cr_assert(request);
    cr_assert(request->type == RQ_CMD_FORWARD);
    cr_assert(list_len(request->arguments) == 0);
    free(input);
    request_destroy(request);
}

Test(request_parse_from_input, success_without_arg_2)
{
    char *input = strdup("Incantation");
    request_t *request = request_parse_from_input(input, CLIENT_DRONE);

    cr_assert(request);
    cr_assert(request->type == RQ_CMD_INCANTATION);
    cr_assert(list_len(request->arguments) == 0);
    free(input);
    request_destroy(request);
}

Test(request_parse_from_input, success_without_arg_3)
{
    char *input = strdup("msz");
    request_t *request = request_parse_from_input(input, CLIENT_DRONE);

    cr_assert(request);
    cr_assert(request->type == RQ_MAP_SIZE);
    cr_assert(list_len(request->arguments) == 0);
    free(input);
    request_destroy(request);
}

Test(request_parse_from_input, success_without_arg_4)
{
    char *input = strdup("bct");
    request_t *request = request_parse_from_input(input, CLIENT_DRONE);

    cr_assert(request);
    cr_assert(request->type == RQ_TILE_CONTENT);
    cr_assert(list_len(request->arguments) == 0);
    free(input);
    request_destroy(request);
}

Test(request_parse_from_input, success_with_one_arg_1)
{
    char *input = strdup("Right arg1");
    request_t *request = request_parse_from_input(input, CLIENT_DRONE);

    cr_assert(request);
    cr_assert(request->type == RQ_CMD_RIGHT);
    cr_assert(list_len(request->arguments) == 1);
    cr_assert_str_eq(NODE_STR(list_begin(request->arguments)), "arg1");
    free(input);
    request_destroy(request);
}

Test(request_parse_from_input, success_with_one_arg_2)
{
    char *input = strdup("mct arg1");
    request_t *request = request_parse_from_input(input, CLIENT_DRONE);

    cr_assert(request);
    cr_assert(request->type == RQ_MAP_CONTENT);
    cr_assert(list_len(request->arguments) == 1);
    cr_assert_str_eq(NODE_STR(list_begin(request->arguments)), "arg1");
    free(input);
    request_destroy(request);
}

Test(request_parse_from_input, success_with_many_args_1)
{
    char *input = strdup("Left arg1 arg2");
    request_t *request = request_parse_from_input(input, CLIENT_DRONE);

    cr_assert(request);
    cr_assert(request->type == RQ_CMD_LEFT);
    cr_assert(list_len(request->arguments) == 2);
    cr_assert_str_eq(NODE_STR(list_begin(request->arguments)), "arg1");
    cr_assert_str_eq(NODE_STR(list_end(request->arguments)), "arg2");
    free(input);
    request_destroy(request);
}

Test(request_parse_from_input, success_with_many_args_2)
{
    char *input = strdup("tna arg1 arg2");
    request_t *request = request_parse_from_input(input, CLIENT_DRONE);

    cr_assert(request);
    cr_assert(request->type == RQ_TEAM_NAMES);
    cr_assert(list_len(request->arguments) == 2);
    cr_assert_str_eq(NODE_STR(list_begin(request->arguments)), "arg1");
    cr_assert_str_eq(NODE_STR(list_end(request->arguments)), "arg2");
    free(input);
    request_destroy(request);
}

Test(request_parse_from_input, success_with_many_args_3)
{
    char *input = strdup("ppo arg1 arg2 arg3 arg4 arg5");
    request_t *request = request_parse_from_input(input, CLIENT_DRONE);

    cr_assert(request);
    cr_assert(request->type == RQ_PLAYER_POSITION);
    cr_assert(list_len(request->arguments) == 5);
    cr_assert_str_eq(NODE_STR(list_get(request->arguments, 0)), "arg1");
    cr_assert_str_eq(NODE_STR(list_get(request->arguments, 1)), "arg2");
    cr_assert_str_eq(NODE_STR(list_get(request->arguments, 2)), "arg3");
    cr_assert_str_eq(NODE_STR(list_get(request->arguments, 3)), "arg4");
    cr_assert_str_eq(NODE_STR(list_get(request->arguments, 4)), "arg5");
    free(input);
    request_destroy(request);
}

Test(request_parse_from_input, fail_unkown_request)
{
    char *input = strdup("unkown_request");
    request_t *request = request_parse_from_input(input, CLIENT_DRONE);

    cr_assert(request && !request->is_valid);
    free(input);
    request_destroy(request);
}

Test(request_parse_from_input, fail_unkown_request_w_spaces_1)
{
    char *input = strdup("unkown_request ");
    request_t *request = request_parse_from_input(input, CLIENT_DRONE);

    cr_assert(request && !request->is_valid);
    free(input);
    request_destroy(request);
}

Test(request_parse_from_input, fail_unkown_request_w_spaces_2)
{
    char *input = strdup(" unkown_request");
    request_t *request = request_parse_from_input(input, CLIENT_DRONE);

    cr_assert(request && !request->is_valid);
    free(input);
    request_destroy(request);
}

Test(request_parse_from_input, fail_unkown_request_w_spaces_3)
{
    char *input = strdup("    unkown_request  ");
    request_t *request = request_parse_from_input(input, CLIENT_DRONE);

    cr_assert(request && !request->is_valid);
    free(input);
    request_destroy(request);
}

Test(request_parse_from_input, fail_kown_request_w_spaces_1)
{
    char *input = strdup("Forward ");
    request_t *request = request_parse_from_input(input, CLIENT_DRONE);

    cr_assert(request && !request->is_valid);
    free(input);
    request_destroy(request);
}

Test(request_parse_from_input, fail_kown_request_w_spaces_2)
{
    char *input = strdup(" Forward");
    request_t *request = request_parse_from_input(input, CLIENT_DRONE);

    cr_assert(request && !request->is_valid);
    free(input);
    request_destroy(request);
}

Test(request_parse_from_input, fail_kown_request_w_spaces_3)
{
    char *input = strdup("    Forward  ");
    request_t *request = request_parse_from_input(input, CLIENT_DRONE);

    cr_assert(request && !request->is_valid);
    free(input);
    request_destroy(request);
}

Test(request_parse_from_input, fail_arg_w_bad_spaces_1)
{
    char *input = strdup("Forward  arg_1");
    request_t *request = request_parse_from_input(input, CLIENT_DRONE);

    cr_assert(request && !request->is_valid);
    free(input);
    request_destroy(request);
}

Test(request_parse_from_input, fail_arg_w_bad_spaces_2)
{
    char *input = strdup("Forward arg_1 ");
    request_t *request = request_parse_from_input(input, CLIENT_DRONE);

    cr_assert(request && !request->is_valid);
    free(input);
    request_destroy(request);
}

Test(request_parse_from_input, fail_args_w_bad_spaces_1)
{
    char *input = strdup("Forward  arg_1 arg2");
    request_t *request = request_parse_from_input(input, CLIENT_DRONE);

    cr_assert(request && !request->is_valid);
    free(input);
    request_destroy(request);
}

Test(request_parse_from_input, fail_args_w_bad_spaces_2)
{
    char *input = strdup("Forward arg_1  arg2");
    request_t *request = request_parse_from_input(input, CLIENT_DRONE);

    cr_assert(request && !request->is_valid);
    free(input);
    request_destroy(request);
}

Test(request_parse_from_input, fail_args_w_bad_spaces_3)
{
    char *input = strdup("Forward arg_1 arg2 ");
    request_t *request = request_parse_from_input(input, CLIENT_DRONE);

    cr_assert(request && !request->is_valid);
    free(input);
    request_destroy(request);
}