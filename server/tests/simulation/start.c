/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** start
*/

#include <criterion/criterion.h>

#include "simulation/simulation.h"

void set_dummy_args(arguments_t *args, size_t c)
{
    args->clients_nb = c;
    args->team_names = string_list_create();
    args->width = 10;
    args->height = 10;
}

Test(simulation_start, basic)
{
    arguments_t args;
    simulation_t sim = {0};

    set_dummy_args(&args, 10);
    string_list_push_back(args.team_names, "Team1");
    string_list_push_back(args.team_names, "Team2");
    string_list_push_back(args.team_names, "Team3");
    string_list_push_back(args.team_names, "Team4");
    string_list_push_back(args.team_names, "Team5");
    cr_assert(simulation_start(&args, &sim) == SIMULATION_SUCCESS);
    cr_assert(list_len(sim.teams) == 5);
    cr_assert_str_eq(NODE_PTR(list_get(sim.teams, 0), team_t)->name, "Team1");
    cr_assert_str_eq(NODE_PTR(list_get(sim.teams, 1), team_t)->name, "Team2");
    cr_assert_str_eq(NODE_PTR(list_get(sim.teams, 2), team_t)->name, "Team3");
    cr_assert_str_eq(NODE_PTR(list_get(sim.teams, 3), team_t)->name, "Team4");
    cr_assert_str_eq(NODE_PTR(list_get(sim.teams, 4), team_t)->name, "Team5");
}

Test(simulation_start, no_teams)
{
    arguments_t args;
    simulation_t sim = {0};

    set_dummy_args(&args, 10);
    cr_assert(simulation_start(&args, &sim) == SIMULATION_SUCCESS);
    cr_assert(list_len(sim.teams) == 0);
}