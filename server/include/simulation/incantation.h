/*
** EPITECH PROJECT, 2021
** server
** File description:
** incantation
*/

#ifndef INCANTATION_H_
#define INCANTATION_H_

#include <stddef.h>

#include "simulation/tile.h"
#include "simulation/drone.h"
#include "simulation/resources.h"

#define ELEVATION_MAX_LVL               8
#define INCANTATION_TIME_TO_ELEVATE     300

typedef struct elevation_requirement_s
{
    size_t drone_nb;
    size_t drone_lvl;
    size_t requirements[RESOURCE_NB];
} elevation_requirement_t;

typedef struct incantation_s
{
    const elevation_requirement_t * requirements;
    int                             time_until_elevation;
    drone_t *                       owner;
} incantation_t;

incantation_t *incantation_create(drone_t *owner);
void incantation_destroy(incantation_t *incantation);


const elevation_requirement_t *incantation_find_requirements(size_t drone_lvl);

extern const elevation_requirement_t elevation_requirements[];
extern const size_t elevation_requirements_size;

#endif /* !INCANTATION_H_ */
