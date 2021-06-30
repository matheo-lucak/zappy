/*
** EPITECH PROJECT, 2021
** server
** File description:
** eat
*/

#include "simulation/drone.h"

bool drone_eat(drone_t *drone)
{
    if (drone->satiety > 0) {
        drone->satiety -= 1;
        return true;
    }
    if (inventory_get_food_amount(drone->inventory) > 0) {
        inventory_remove_item(drone->inventory, RESOURCE_FOOD, 1);
        drone->satiety = DRONE_SATIETY_PER_FOOD - 1;
        return true;
    }
    return false;
}
