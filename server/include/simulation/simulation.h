/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** simulation
*/

#ifndef SIMULATION_H_
#define SIMULATION_H_

#include "arguments.h"

#include "simulation/map.h"
#include "simulation/team.h"

#define SIMULATION_EXIT     84
#define SIMULATION_ERROR    1
#define SIMULATION_SUCCESS  0


typedef struct simulation_s
{
    int             default_team_free_slot;
    map_t *         map;
    ptr_list_t *    teams;
} simulation_t;

int simulation_start(const arguments_t *args, simulation_t *sim);
void simulation_stop(simulation_t *sim);

void simulation_handle(simulation_t *sim);
void simulation_handle_eggs(simulation_t *sim);

team_t *simulation_find_team_from_drone(simulation_t *sim, drone_t *drone);

#endif /* !SIMULATION_H_ */
