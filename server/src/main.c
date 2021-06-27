/*
** EPITECH PROJECT, 2021
** Zappy [WSL: Ubuntu]
** File description:
** main
*/

#include "arg_parser.h"
#include "server/server.h"

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
