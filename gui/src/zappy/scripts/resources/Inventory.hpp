/*
** EPITECH PROJECT, 2021
** gui [WSL: Ubuntu]
** File description:
** Inventory
*/

#pragma once

#include <unordered_map>

enum Resource
{
    FOOD,
    LINEMATE,
    DERAUMERE,
    MENDIANE,
    SIBUR,
    PHIRAS,
    THYSTAME,
};

class Inventory
{
private:
    std::unordered_map<Resource, unsigned int> slots;

public:
    Inventory();
    ~Inventory() noexcept = default;

    unsigned int get_item_quantity(Resource resource) const noexcept;
    void add_item(Resource resource, unsigned int quantity);
    void delete_item(Resource resource, unsigned int quantity);
};
