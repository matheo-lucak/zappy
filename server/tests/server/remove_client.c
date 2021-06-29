/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** remove_client
*/

#include <criterion/criterion.h>

#include "server/server.h"
#include "simulation/incantation.h"

void set_dummy_server(server_t *s, size_t team_nb, size_t drone_p_team)
{
    size_t i = 0;
    team_t *team = NULL;
    drone_t *drone = NULL;
    client_t *client = NULL;

    s->clients = ptr_list_create((node_dtor_t)&client_destroy);
    s->sim.teams = ptr_list_create((node_dtor_t)&team_destroy);
    s->sim.incantations = ptr_list_create((node_dtor_t)&incantation_destroy);
    s->sim.map = map_create(10, 10);
    for (; team_nb; team_nb--) {
        team = team_create("Dummy team", 4096);
        ptr_list_push_back(s->sim.teams, team);
        for (i = drone_p_team; i; i--) {
            client = client_create();
            drone = drone_create(VEC2U(0, 0), true);
            client_to_drone(client, drone);
            ptr_list_push_back(s->clients, client);
            ptr_list_push_back(team->drones, drone);
        }
    }
}

Test(server_remove_client, basic_remove)
{
    server_t s = {0};
    team_t *t1 = NULL;
    team_t *t2 = NULL;

    set_dummy_server(&s, 2, 2);
    t1 = NODE_PTR(list_get(s.sim.teams, 0), team_t);
    t2 = NODE_PTR(list_get(s.sim.teams, 1), team_t);
    cr_assert(list_len(s.clients) == 4);
    server_remove_client(&s, NODE_PTR(list_get(s.clients, 0), client_t));
    cr_assert(list_len(s.clients) == 3);
    cr_assert(list_len(t1->drones) == 1 && list_len(t2->drones) == 2);
    server_remove_client(&s, NODE_PTR(list_get(s.clients, 0), client_t));
    cr_assert(list_len(t1->drones) == 0 && list_len(t2->drones) == 2);
    server_remove_client(&s, NODE_PTR(list_get(s.clients, 0), client_t));
    cr_assert(list_len(t1->drones) == 0 && list_len(t2->drones) == 1);
    server_remove_client(&s, NODE_PTR(list_get(s.clients, 0), client_t));
    cr_assert(list_len(t1->drones) == 0 && list_len(t2->drones) == 0);
    cr_assert(list_len(s.clients) == 0);
    server_stop(&s);
}

Test(server_remove_client, nested_remove)
{
    server_t s = {0};
    team_t *t1 = NULL;
    team_t *t2 = NULL;

    set_dummy_server(&s, 10, 20);
    t1 = NODE_PTR(list_get(s.sim.teams, 3), team_t);
    t2 = NODE_PTR(list_get(s.sim.teams, 9), team_t);
    cr_assert(list_len(s.clients) == 200);
    server_remove_client(&s, NODE_PTR(list_get(s.clients, 199), client_t));
    cr_assert(list_len(s.clients) == 199);
    cr_assert(list_len(t1->drones) == 20 && list_len(t2->drones) == 19);
    server_remove_client(&s, NODE_PTR(list_get(s.clients, 191), client_t));
    cr_assert(list_len(t1->drones) == 20 && list_len(t2->drones) == 18);
    server_remove_client(&s, NODE_PTR(list_get(s.clients, 1), client_t));
    cr_assert(list_len(t1->drones) == 20 && list_len(t2->drones) == 18);
    server_remove_client(&s, NODE_PTR(list_get(s.clients, 0), client_t));
    cr_assert(list_len(t1->drones) == 20 && list_len(t2->drones) == 18);
    cr_assert(list_len(s.clients) == 196);
    server_stop(&s);
}

Test(server_remove_client, remove_from_incantation)
{
    server_t s = {0};
    drone_t *drone = NULL;
    team_t *team = NULL;
    tile_t *tile = NULL;
    incantation_t *inc = NULL;

    set_dummy_server(&s, 10, 20);
    cr_assert(list_len(s.clients) == 200);
    tile = s.sim.map->tiles[0][0];
    team = NODE_PTR(list_get(s.sim.teams, 0), team_t);
    drone = NODE_PTR(list_begin(team->drones), drone_t);
    inc = incantation_create(drone, tile);
    tile_add_drone(tile, drone);
    ptr_list_push_back(s.sim.incantations, inc);
    cr_assert(list_len(s.sim.incantations) == 1 && inc->owner == drone);
    cr_assert(list_len(tile->drones) == 1);
    server_remove_client(&s, NODE_PTR(list_get(s.clients, 0), client_t));
    cr_assert(list_len(s.clients) == 199);
    cr_assert(list_len(s.sim.incantations) == 1 && inc->owner == NULL);
    cr_assert(list_len(tile->drones) == 0);
    server_stop(&s);
}