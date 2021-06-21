/*
** EPITECH PROJECT, 2021
** B-YEP-410-BDX-4-1-zappy-guillaume.bogard-coquard
** File description:
** simulators
*/

#ifndef SIMULATORS_H_
#define SIMULATORS_H_

#include "simulation/simulation.h"
#include "server/request/request.h"

typedef void (*simulator_t)(simulation_t *, client_t *, request_t *);

#endif /* !SIMULATORS_H_ */
