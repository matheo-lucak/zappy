/*
** EPITECH PROJECT, 2021
** server
** File description:
** handle_parsing
*/

#include <criterion/criterion.h>
#include <string.h>

#include "server/request/request.h"
#include "server/server.h"del + 1

static void setup_dummy_server(server_t *s, client_type_t c_type, char *buffer)
{
    client_t *c = client_create();

    s->clients = ptr_list_create((node_dtor_t)&client_destroy);
    ptr_list_push_back(s->clients, c);
    c->input_stock = buffer ? strdup(buffer) : NULL;
    c->type = c_type;
}

static void destroy_dummy_server(server_t *s)
{
    ptr_list_destroy(s->clients);
}

Test(server_handle_request_parsing, perfect_input)
{
    server_t s = {0};
    client_t *c = NULL;
    request_t *r1 = NULL;

    setup_dummy_server(&s, CLIENT_DRONE, "Look\n");
    c = NODE_PTR(list_begin(s.clients), client_t);
    server_handle_request_parsing(&s);
    cr_assert(list_len(c->pending_requests) == 1);
    r1 = NODE_PTR(list_get(c->pending_requests, 0), request_t);
    cr_assert(r1->type == RQ_CMD_LOOK);
    cr_assert_str_empty(c->input_stock);
    destroy_dummy_server(&s);
}

Test(server_handle_request_parsing, not_enough_data)
{
    server_t s = {0};
    client_t *c = NULL;

    setup_dummy_server(&s, CLIENT_DRONE, "Look");
    c = NODE_PTR(list_begin(s.clients), client_t);
    server_handle_request_parsing(&s);
    cr_assert(list_len(c->pending_requests) == 0);
    cr_assert_str_eq(c->input_stock, "Look");
    destroy_dummy_server(&s);
}

Test(server_handle_request_parsing, multiple_request_prefect)
{
    server_t s = {0};
    client_t *c = NULL;
    request_t *r1 = NULL;
    request_t *r2 = NULL;
    request_t *r3 = NULL;

    setup_dummy_server(&s, CLIENT_DRONE, "Look\nForward\nConnect_nbr\n");
    c = NODE_PTR(list_begin(s.clients), client_t);
    server_handle_request_parsing(&s);
    cr_assert(list_len(c->pending_requests) == 3);
    r1 = NODE_PTR(list_get(c->pending_requests, 0), request_t);
    r2 = NODE_PTR(list_get(c->pending_requests, 1), request_t);
    r3 = NODE_PTR(list_get(c->pending_requests, 2), request_t);
    cr_assert(r1->type == RQ_CMD_LOOK);
    cr_assert(r2->type == RQ_CMD_FORWARD);
    cr_assert(r3->type == RQ_CMD_CONNECT_NBR);
    cr_assert_str_empty(c->input_stock);
    destroy_dummy_server(&s);
}

Test(server_handle_request_parsing, multiple_request_residue)
{
    server_t s = {0};
    client_t *c = NULL;
    request_t *r1 = NULL;
    request_t *r2 = NULL;
    request_t *r3 = NULL;

    setup_dummy_server(&s, CLIENT_DRONE, "Look\nForward\nConnect_nbr\nLook");
    c = NODE_PTR(list_begin(s.clients), client_t);
    server_handle_request_parsing(&s);
    r1 = NODE_PTR(list_get(c->pending_requests, 0), request_t);
    r2 = NODE_PTR(list_get(c->pending_requests, 1), request_t);
    r3 = NODE_PTR(list_get(c->pending_requests, 2), request_t);
    cr_assert(list_len(c->pending_requests) == 3);
    cr_assert(r1->type == RQ_CMD_LOOK);
    cr_assert(r2->type == RQ_CMD_FORWARD);
    cr_assert(r3->type == RQ_CMD_CONNECT_NBR);
    cr_assert_str_eq(c->input_stock, "Look");
    destroy_dummy_server(&s);
}
