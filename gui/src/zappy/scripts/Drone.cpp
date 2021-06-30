/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Drone
*/

#include "Drone.hpp"

SCRIPT_INIT(Drone)

Drone::Drone(ecs::GameObject &gameObject) noexcept : ecs::Script{gameObject}
{
}

std::unique_ptr<ecs::Script> Drone::copy(ecs::GameObject &copyOn) const noexcept
{
    return std::make_unique<Drone>(copyOn);
}

void Drone::Start() noexcept
{
}

void Drone::Update() noexcept
{
}

void Drone::updateInventory(Resource rs_id, unsigned int quantity)
{
    m_inventory.set_item(rs_id, quantity);
}
