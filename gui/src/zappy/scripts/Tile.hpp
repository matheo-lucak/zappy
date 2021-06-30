/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Tile
*/

#pragma once

#include "ECS/Script.hpp"

#include "resources/Inventory.hpp"

class Tile : public ecs::Script
{
public:
    Inventory m_inventory;

private:
    ecs::GameObject *m_tileInventory_obj;

public:
    Tile(ecs::GameObject &gameObject) noexcept;
    ~Tile() = default;

    std::unique_ptr<ecs::Script> copy(ecs::GameObject &copyOn) const noexcept override;

    utils::Vector2f getInventoryToWorldScreen(void) const noexcept;

    void Awake() noexcept override;
    void Start() noexcept override;
    void Update() noexcept override;

public:
    ecs::GameObject *m_mineral = nullptr;
    ecs::GameObject *m_food = nullptr;
};

DECLARE_AS_SCRIPT(Tile)
