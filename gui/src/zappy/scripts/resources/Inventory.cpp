/*
** EPITECH PROJECT, 2021
** gui [WSL: Ubuntu]
** File description:
** Inventory
*/

#include "Inventory.hpp"

Inventory::Inventory() :
    slots{{FOOD, 0},
        {LINEMATE, 0},
        {DERAUMERE, 0},
        {MENDIANE, 0},
        {SIBUR, 0},
        {PHIRAS, 0},
        {THYSTAME, 0}}
{
}

unsigned int Inventory::get_item_quantity(Resource resource) const noexcept
{
    auto it = slots.find(resource);

    if (it == slots.end())
        return 0;
    return it->second;
}

void Inventory::add_item(Resource resource, unsigned int quantity)
{
    if (quantity == 0)
        return;

    auto it = slots.find(resource);

    if (it == slots.end()) {
        slots.insert({resource, quantity});
        return;
    }
    it->second += quantity;
}
