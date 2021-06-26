/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** cmd_eject
*/

#include "server/request/handler.h"
#include "server/response/response.h"
#include "simulation/drone.h"

static local_direction_t get_eject_direction(direction_t facing_direction,
                                            direction_t pushed_direction)
{
    if (pushed_direction == UP) {
        if (facing_direction == UP)
            return LCL_DOWN;
        if (facing_direction == DOWN)
            return LCL_UP;
        if (facing_direction == LEFT)
            return LCL_LEFT;
        if (facing_direction == RIGHT)
            return LCL_RIGHT;
    }
    if (pushed_direction == DOWN) {
        if (facing_direction == UP)
            return LCL_UP;
        if (facing_direction == DOWN)
            return LCL_DOWN;
        if (facing_direction == LEFT)
            return LCL_RIGHT;
        if (facing_direction == RIGHT)
            return LCL_LEFT;
    }
    if (pushed_direction == LEFT) {
        if (facing_direction == UP)
            return LCL_RIGHT;
        if (facing_direction == DOWN)
            return LCL_LEFT;
        if (facing_direction == LEFT)
            return LCL_DOWN;
        if (facing_direction == RIGHT)
            return LCL_UP;
    }
    if (pushed_direction == RIGHT) {
        if (facing_direction == UP)
            return LCL_LEFT;
        if (facing_direction == DOWN)
            return LCL_RIGHT;
        if (facing_direction == LEFT)
            return LCL_UP;
        if (facing_direction == RIGHT)
            return LCL_DOWN;
    }
    return LCL_UNKNOWN;
}

static int client_drone_finder(client_t *client, drone_t *drone)
{
    if ((void *)client->drone == (void *)drone)
        return 0;
    return 1;
}

client_t *get_client_from_drone(server_t *s, drone_t *drone)
{
    const node_t *node = ptr_list_find_cmp(s->clients, drone, &client_drone_finder);

    if (!node)
        return NULL;
    return NODE_PTR(node, client_t);
}

void request_handler_cmd_eject(server_t *s, client_t *c, request_t *r)
{
    response_t *response = NULL;
    client_t *eject_c = NULL;
    local_direction_t eject_index;

    if (list_empty(s->s.map->tiles[c->drone->y][c->drone->x]->drones)) {
        client_add_response(c, response_create(RESPONSE_KO));
        return;
    }
    list_foreach(d, s->s.map->tiles[c->drone->y][c->drone->x]->drones) {
        if ((void *)d == (void *)c->drone)
            continue;
        drone_eject(NODE_PTR(d, drone_t), s->s.map, c->drone->facing_direction);
        eject_c = get_client_from_drone(s, NODE_PTR(d, drone_t));
        if (eject_c) {
            eject_index = get_eject_direction(NODE_PTR(d, drone_t)->facing_direction, c->drone->facing_direction);
            client_add_response(c, response_create(RESPONSE_EJECT, eject_index));
        }
    }
    client_add_response(c, response_create(RESPONSE_OK));
}
