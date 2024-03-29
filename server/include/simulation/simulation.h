/*
** EPITECH PROJECT, 2021
** Zappy
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

#define MAXED_DRONE_TO_WIN  6

typedef struct server_s server_t;

typedef struct simulation_s
{
    int             default_team_free_slot;
    map_t *         map;
    ptr_list_t *    teams;
    ptr_list_t *    incantations;
} simulation_t;

int simulation_start(const arguments_t *args, simulation_t *sim);
void simulation_stop(simulation_t *sim);

void simulation_handle(server_t *s);
void simulation_handle_eggs(server_t *s);
void simulation_handle_incantation(server_t *s);
void simulation_handle_food(server_t *s);
void simulation_check_end_of_game(server_t *s);

void simulation_remove_drone(simulation_t *sim, drone_t *drone);

team_t *simulation_find_team_from_drone(simulation_t *sim, drone_t *drone);

unsigned int get_next_entity_id(void);

#endif /* !SIMULATION_H_ */
