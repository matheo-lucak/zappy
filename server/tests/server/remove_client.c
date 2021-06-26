/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** remove_client
*/

#include <criterion/criterion.h>

#include "server/server.h"

void set_dummy_server(server_t *s, size_t team_nb, size_t drone_p_team)
{
    size_t i = 0;
    team_t *team = NULL;
    drone_t *drone = NULL;
    client_t *client = NULL;

    s->clients = ptr_list_create((void *)&client_destroy);
    s->s.teams = ptr_list_create((void *)&drone_destroy);
    for (; team_nb; team_nb--) {
        team = team_create("Dummy team", 4096);
        ptr_list_push_back(s->s.teams, team);
        for (i = drone_p_team; i; i--) {
            client = client_create();
            drone = drone_create(0, 0);
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
    t1 = NODE_PTR(list_get(s.s.teams, 0), team_t);
    t2 = NODE_PTR(list_get(s.s.teams, 1), team_t);
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
}

Test(server_remove_client, nested_remove)
{
    server_t s = {0};
    team_t *t1 = NULL;
    team_t *t2 = NULL;

    set_dummy_server(&s, 10, 20);
    t1 = NODE_PTR(list_get(s.s.teams, 3), team_t);
    t2 = NODE_PTR(list_get(s.s.teams, 9), team_t);
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
}