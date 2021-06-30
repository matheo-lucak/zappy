/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Egg
*/

#pragma once

#include "ECS/Script.hpp"

class Egg : public ecs::Script
{
public:
    Egg(ecs::GameObject &gameObject) noexcept;
    ~Egg() = default;

    std::unique_ptr<ecs::Script> copy(ecs::GameObject &copyOn) const noexcept override;

    void Start() noexcept override;
    void Update() noexcept override;

    size_t id;
    int x = 0;
    int y = 0;
};

DECLARE_AS_SCRIPT(Egg)
