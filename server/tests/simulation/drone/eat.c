/*
** EPITECH PROJECT, 2021
** server
** File description:
** eat
*/

#include <criterion/criterion.h>

#include "simulation/drone.h"

Test(drone_eat, live_and_die)
{
    drone_t *drone = drone_create(0, 0, true);
    int ticks = 0;
    int tick_to_death = DRONE_SATIETY_PER_FOOD * DRONE_DEFAULT_FOOD_QUANTITY;

    for (; ticks < tick_to_death ; ticks++) {
        cr_assert(drone_eat(drone));
    }
    cr_assert(drone_eat(drone) == false);
}