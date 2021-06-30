/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** check_end_of_game
*/

#include "server/server.h"
#include "simulation/simulation.h"
#include "simulation/incantation.h"
#include "server/response/response.h"

static void server_notification_seg(server_t *s, team_t *team)
{
    server_add_notification(s, response_create(RESPONSE_SEG, team->name));
}

void simulation_check_end_of_game(server_t *s)
{
    team_t *team = NULL;
    drone_t *drone = NULL;
    size_t maxed_drone = 0;

    list_foreach(team_it, s->sim.teams) {
        maxed_drone = 0;
        team = NODE_PTR(team_it, team_t);
        list_foreach(drone_it, team->drones) {
            drone = NODE_PTR(drone_it, drone_t);
            if (drone->elevation_lvl >= ELEVATION_MAX_LVL) {
                maxed_drone += 1;
            }
        }
        if (maxed_drone >= MAXED_DRONE_TO_WIN) {
            server_notification_seg(s, team);
        }
    }
}