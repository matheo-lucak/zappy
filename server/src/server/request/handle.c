/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** handle
*/

#include "server/server.h"
#include "server/request/request.h"
#include "server/response/response.h"

static void server_handle_single_request(server_t *s, client_t *c)
{
    request_t *request = NULL;

    if (list_len(c->pending_requests) == 0)
        return;
    request = NODE_PTR(list_begin(c->pending_requests), request_t);
    if (request_checker(c, request) == false) {
        client_add_response(c, response_create(RESPONSE_KO));
        list_pop_front(c->pending_requests);
        return;
    }
    if (request->time_limit > 0) {
        request->time_limit -= 1;
        return;
    }
    request->time_limit -= 1;
    if (request->handler)
        request->handler(s, c, request);
    list_pop_front(c->pending_requests);
}

void server_handle_request(server_t *s)
{
    client_t *c = NULL;

    list_foreach(node, s->clients) {
        c = NODE_PTR(node, client_t);
        server_handle_single_request(s, c);
    }
}
