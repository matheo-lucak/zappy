/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Drone
*/

#pragma once

#include "ECS/Script.hpp"
#include "resources/Inventory.hpp"

class Drone : public ecs::Script
{
public:
    enum Direction
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

public:
    Drone(ecs::GameObject &gameObject) noexcept;
    ~Drone() = default;

    std::unique_ptr<ecs::Script> copy(ecs::GameObject &copyOn) const noexcept override;

    void Start() noexcept override;
    void Update() noexcept override;

    void updateInventory(Resource rs_id, unsigned int quantity);

    size_t      id      = 0;
    bool        active  = false;
    size_t      lvl     = 1;
    Direction   dir     = UP;
    int         x       = 0;
    int         y       = 0;
    Inventory   m_inventory;
    std::string m_team_name;
};

DECLARE_AS_SCRIPT(Drone)
