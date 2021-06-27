/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** main
*/

#include "arg_parser.h"
#include "server/server.h"

#include "simulation/incantation.h"

void set_dummy_server(server_t *s, size_t team_nb, size_t drone_p_team)
{
    size_t i = 0;
    team_t *team = NULL;
    drone_t *drone = NULL;
    client_t *client = NULL;

    s->clients = ptr_list_create((void *)&client_destroy);
    s->sim.teams = ptr_list_create((void *)&team_destroy);
    s->sim.incantations = ptr_list_create((void *)&incantation_destroy);
    s->sim.map = map_create(10, 10);
    for (; team_nb; team_nb--) {
        team = team_create("Dummy team", 4096);
        ptr_list_push_back(s->sim.teams, team);
        for (i = drone_p_team; i; i--) {
            client = client_create();
            drone = drone_create(0, 0, true);
            client_to_drone(client, drone);
            ptr_list_push_back(s->clients, client);
            ptr_list_push_back(team->drones, drone);
        }
    }
}


int main(int ac, char **av)
{
    server_t s = {0};
    team_t *t1 = NULL;
    team_t *t2 = NULL;

    set_dummy_server(&s, 2, 2);
    t1 = NODE_PTR(list_get(s.sim.teams, 0), team_t);
    t2 = NODE_PTR(list_get(s.sim.teams, 1), team_t);
    server_remove_client(&s, NODE_PTR(list_get(s.clients, 0), client_t));
    server_remove_client(&s, NODE_PTR(list_get(s.clients, 0), client_t));
    server_remove_client(&s, NODE_PTR(list_get(s.clients, 0), client_t));
    server_remove_client(&s, NODE_PTR(list_get(s.clients, 0), client_t));
    server_stop(&s);

    arguments_t args = arguments_default_values();

    if (parse_arguments(ac, av, &args))
        return SERVER_EXIT;
    return server_launch(&args);
}
