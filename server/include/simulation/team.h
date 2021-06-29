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
    unsigned int  default_slots_nb;
    unsigned int        free_slots_nb;
    char *              name;
    ptr_list_t *        drones;
    ptr_list_t *        eggs;
} team_t;

/**
* @brief Creates a team.
*
* @param name The name of the team.
* @param free_slots_nb The default slot avaible for drones
* @return response_t* A pointer to the newly allocated team.
*/
team_t *team_create(const char *name, unsigned int free_slots_nb);

/**
* @brief Releases memory previously allocated to a team.
*
* @param team The team on which memory needs to be released.
*/
void team_destroy(team_t *team);

/**
* @brief Adds a drone to a team.
*
* @param team The team.
* @param team The drone.
* @return true if the operation is successful.
*/
bool team_add_drone(team_t *team, drone_t *drone);

/**
* @brief Deletes a drone from a team
*
* @param team The team.
* @param team The drone.
* @return true if the operation is successful.
*/
bool team_delete_drone(team_t *team, drone_t *drone);

/**
* @brief Checks if a team contains the given drone.
*
* @param team The team.
* @param team The drone.
* @return true if the drone is in the team.
*/
bool team_has_drone(team_t *team, const drone_t *drone);

/**
* @brief Find or Creates a new drone ready to be used (by a client)
*
* @param team The team.
* @return A new drone if the team has enough slots
* @return NULL in other cases
*/
drone_t *team_new_active_drone(team_t *team, vector2u_t pos);

/**
* @brief Finds and returns the first inactive drone in the team
*
* @param team The team.
* @return drone_t A pointer to the first inactive drone.
* @return NULL if not found.
*/
drone_t *team_find_unactive_drone(team_t *team);

/**
* @brief Adds a egg to a team.
*
* @param team The team.
* @param team The egg.
* @return true if the operation is successful.
*/
bool team_add_egg(team_t *team, egg_t *egg);

#endif /* !TEAM_H_ */
