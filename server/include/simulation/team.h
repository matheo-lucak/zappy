/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** team
*/

#ifndef TEAM_H_
#define TEAM_H_

#include <mylist.h>

#include "simulation/drone.h"
#include "simulation/egg.h"
#include "server/client.h"

#define TEAM_DEFAULT_NAME "Unkown team"

typedef struct team_s
{
    char *          name;
    unsigned int    free_slots_nb;
    ptr_list_t *    drones;
    ptr_list_t *    eggs;
} team_t;

team_t *team_create(const char *name, unsigned int free_slots_nb);
void team_destroy(team_t *team);

bool team_add_drone(team_t *team, drone_t *drone);
bool team_delete_drone(team_t *team, drone_t *drone);
bool team_has_drone(team_t *team, const drone_t *drone);

bool team_add_egg(team_t *team, egg_t *egg);

#endif /* !TEAM_H_ */
